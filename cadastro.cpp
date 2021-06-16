#include "cadastro.h"
#include "iostream"
#include "ui_cadastro.h"
#include <QMessageBox>
#include <QPixmap>

cadastro::cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastro)
{
    setWindowTitle("Cadastro Insumo");
    ui->setupUi(this);
    QPixmap pix(":/src/src/white.png");
    ui->label_7->setPixmap((pix.scaled(900,800,Qt::KeepAspectRatio)));
}

cadastro::~cadastro()
{
    delete ui;
}

Insumo* cadastro::getInsumo(){
    return ins;
}

void cadastro::on_buttonBox_accepted()
{
    Insumo *insumo;

    std::string nome = ui->nome->text().toStdString();
    long quantidade = ui->quantidade->text().toLong();
    double valorUnit = ui->valor->text().toDouble();
    std::string dtVencimento = ui->vencimento->text().toStdString();
    std::string nomeFabricante = ui->fabricante->text().toStdString();

    cadastrovacina vac;
    cadastromedicamento med;
    cadastroepi epi;

    std::string tipoInsumo;
    int tipo;
    tipoInsumo = ui->comboBox->currentText().toStdString();
    if(tipoInsumo=="VACINA"){
        tipo = 1;
    }
    if(tipoInsumo=="MEDICAMENTO"){
        tipo = 2;
    }
    if(tipoInsumo=="EPI"){
        tipo = 3;
    }
    switch(tipo){
        case 1:
            insumo = new Vacina();
            insumo->setAtributos(nome, quantidade, valorUnit, dtVencimento, nomeFabricante, tipo);
            vac.exec();

            ((Vacina*)insumo)->setTipoVac(vac.getTipoVac());
            ((Vacina*)insumo)->setQuantDoses(vac.getQuantDoses());
            ((Vacina*)insumo)->setIntervalo(vac.getIntervalo());
            break;
        case 2:
            insumo = new Medicamento();
            insumo->setAtributos(nome, quantidade, valorUnit, dtVencimento, nomeFabricante, tipo);
            med.exec();

            ((Medicamento*)insumo)->setAdministracao(med.getAdministracao());
            ((Medicamento*)insumo)->setDisponibilizacao(med.getDisponibilizacao());
            ((Medicamento*)insumo)->setDosagem(med.getDosagem());
            break;
        case 3:
            insumo = new Epi();
            insumo->setAtributos(nome, quantidade, valorUnit, dtVencimento, nomeFabricante, tipo);
            epi.exec();

            ((Epi*)insumo)->setTipo(epi.getTipo());
            ((Epi*)insumo)->setAtDescricao(epi.getAtDescricao());
            break;

    }
    this->ins = insumo;
}

