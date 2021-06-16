#include "table.h"
#include "ui_table.h"
#include <QPixmap>


table::table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);
    setWindowTitle("Display de Insumos");
    QPixmap pix(":/src/src/sus.jpg");
    ui->label_7->setPixmap((pix.scaled(900,800,Qt::KeepAspectRatio)));
}

void table::setInsumo(std::vector<Insumo*>insumos, int tipoInsumo){
    int numeroColuna = 0;
    switch (tipoInsumo) {
        case 1:
            numeroColuna = 8;
            break;
        case 2:
            numeroColuna = 8;
            break;
        case 3:
            numeroColuna = 6;
            break;
    }
    ui->tableWidget->setColumnCount(numeroColuna);
    for(unsigned long long i=0; i < insumos.size(); i++){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(insumos[i]->getNome())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(insumos[i]->getQuantidade())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(insumos[i]->getValorUnit())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(insumos[i]->getDtVencimento())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(insumos[i]->getNomeFabricante())));
        switch (tipoInsumo) {
            case 1:
                ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(((Vacina*)insumos[i])->getQuantDoses())));
                ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(((Vacina*)insumos[i])->getTipoVac())));
                ui->tableWidget->setItem(i, 7, new QTableWidgetItem(QString::number(((Vacina*)insumos[i])->getIntervalo())));
                break;
            case 2:
                ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(((Medicamento*)insumos[i])->getDosagem())));
                ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(((Medicamento*)insumos[i])->getAdministracao())));
                ui->tableWidget->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(((Medicamento*)insumos[i])->getDisponibilizacao())));
                break;
            case 3:
                ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(((Epi*)insumos[i])->getTipo())));
                ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(((Epi*)insumos[i])->getAtDescricao())));
                break;
        }
    }
}

table::~table()
{
    delete ui;
}
