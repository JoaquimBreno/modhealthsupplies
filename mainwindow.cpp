#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/src/src/white.png");
    ui->label_2->setPixmap((pix.scaled(600,400,Qt::KeepAspectRatio)));
    QPixmap pox(":/src/src/ministerio.png");
    ui->label->setPixmap((pox.scaled(300,300, Qt::KeepAspectRatio)));
    if(st.lerInsumos(ct)==-1){
        QMessageBox::warning(this, "ERRO", "Erro ao ler arquivo");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCadastrar_Insumo_triggered()
{
    cadastro cadastro;
    cadastro.exec();
    Insumo* ins = cadastro.getInsumo();
    try {
        ct.cadastraInsumosMS(ins);
    }
    catch (std::exception) {
        QMessageBox::about(this,"ERRO", "Não foi possível cadastrar");
    }

    if(st.salvarInsumos(ct)==-1){
        QMessageBox::about(this,"ERRO", "Não foi possível salvar");
    }
}


void MainWindow::on_actionConsulta_Insumos_triggered()
{
    consultalocal local;
    local.exec();
    int tipoLocal = local.getTipo();
    std::vector<std::string> insumos = ct.consultaInsumos(ct.getLocal(tipoLocal));
    try{
    consultainsumo displayinsumo;
    displayinsumo.setVetorInsumos(insumos);
    displayinsumo.exec();
    }
    catch(std::exception){
        QMessageBox::about(this,"ERRO", "Não existe insumo ou não foi consultado");
    }
}


void MainWindow::on_actionConsulta_por_Tipo_triggered()
{
    consultalocalportipo local;
    local.exec();
    int tipoLocal = local.getTipodoLocal();
    int tipo = local.getTipo();
    try{
    std::vector<Insumo*> insumos = ct.consultaInsumoPorTipo(ct.getLocal(tipoLocal), tipo);
    table table;
    table.setInsumo(insumos, tipo);
    table.exec();
    }
    catch(std::exception){
        QMessageBox::about(this,"ERRO", "Não existe insumo ou não foi consultado");
    }
}


void MainWindow::on_actionConsulta_Descri_o_triggered()
{
    std::vector<std::string> insumos = ct.consultaInsumosDescricao();
    if(insumos.size()){
    consultainsumo displayinsumo;
    displayinsumo.setVetorInsumos(insumos);
    displayinsumo.exec();
    }else{
        QMessageBox::about(this,"ERRO", "Não existe insumo ou não foi consultado");
    }
}


void MainWindow::on_actionConsulta_Descri_o_Por_Local_triggered()
{
    consultalocal local;
    local.exec();
    int tipoLocal = local.getTipo();
    std::vector<std::string> insumos = ct.consultaInsumosDescricaoLocal(ct.getLocal(tipoLocal));
    if(insumos.size()){
        consultainsumo displayinsumo;
        displayinsumo.setVetorInsumos(insumos);
        displayinsumo.exec();
    }else{
       QMessageBox::about(this,"ERRO", "Não existe insumo ou não foi consultado");
    }
}


void MainWindow::on_actionDistribuir_Insumo_triggered()
{
    consultanomeinsumo nomeacao;
    nomeacao.exec();

    int tipoDoLocal = nomeacao.getTipodoLocal();
    int quantidade = nomeacao.getQuantidade();
    std::string nome = nomeacao.getNome();
    try{
        for(Insumo* ins : ct.getLocal(0).getInsumos()){
            if(ins->getNome() == nome){
                ct.distribuiInsumo(ct.getLocal(tipoDoLocal), ins, quantidade);
            }
        }
    }
    catch(std::exception){
        QMessageBox::about(this,"ERRO", "Não foi possível distribuir");
    }
}


void MainWindow::on_actionSalvar_em_Arquivo_triggered()
{
    if(st.salvarInsumos(ct)==-1){
        QMessageBox::about(this,"ERRO", "Não foi possível salvar");
    }
}


void MainWindow::on_actionSobre_n_s_triggered()
{
    QMessageBox::about(this,"Sobre", "Código gerado por Luiz Gusttavo, Matheus Mendonça e Joaquim Breno. Data da última release: 15/06/2021.");
}

