#include "consultainsumo.h"
#include "ui_consultainsumo.h"
#include <QPixmap>

consultainsumo::consultainsumo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::consultainsumo)
{
    setWindowTitle("Consulta Insumo");
    ui->setupUi(this);
    QPixmap pix(":/src/src/white.png");
    ui->label_7->setPixmap((pix.scaled(900,800,Qt::KeepAspectRatio)));
}

void consultainsumo::setVetorInsumos(std::vector<std::string>insumos){
    for(unsigned long long i = 0;  i < insumos.size(); i++){
        QString qstr = QString::fromStdString(insumos[i]);
        ui->listWidget->addItem(qstr);
    }
}

consultainsumo::~consultainsumo()
{
    delete ui;
}
