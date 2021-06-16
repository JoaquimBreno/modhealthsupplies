#include "cadastrovacina.h"
#include "ui_cadastrovacina.h"
#include <QPixmap>

cadastrovacina::cadastrovacina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastrovacina)
{
    setWindowTitle("Cadastro Epi");
    ui->setupUi(this);
    QPixmap pix(":/src/src/white.png");
    ui->label_7->setPixmap((pix.scaled(900,800,Qt::KeepAspectRatio)));
}

cadastrovacina::~cadastrovacina()
{
    delete ui;
}

std::string cadastrovacina::getTipoVac()
{
    return tipoVac;
}

int cadastrovacina::getQuantDoses()
{
    return quantDoses;
}

int cadastrovacina::getIntervalo()
{
    return intervalo;
}

void cadastrovacina::on_buttonBox_accepted()
{
   this->tipoVac = ui->tipoVacina->text().toStdString();
   this->quantDoses = ui->quantDoses->text().toInt();
   this->intervalo = ui->intervalo->text().toInt();
}

