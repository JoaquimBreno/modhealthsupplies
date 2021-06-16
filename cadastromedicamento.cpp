#include "cadastromedicamento.h"
#include "ui_cadastromedicamento.h"
#include <QPixmap>

cadastromedicamento::cadastromedicamento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastromedicamento)
{
    setWindowTitle("Cadastro Medicamento");
    ui->setupUi(this);
    QPixmap pix(":/src/src/white.png");
    ui->label_7->setPixmap((pix.scaled(900,800,Qt::KeepAspectRatio)));
}

cadastromedicamento::~cadastromedicamento()
{
    delete ui;
}

std::string cadastromedicamento::getDosagem()
{
    return dosagem;
}

std::string cadastromedicamento::getAdministracao()
{
    return administracao;
}

std::string cadastromedicamento::getDisponibilizacao()
{
    return disponibilizacao;
}

void cadastromedicamento::on_buttonBox_accepted()
{
    this->administracao = ui->administracao->text().toStdString();
    this->disponibilizacao = ui->disponibilizacao->text().toStdString();
    this->dosagem = ui->dosagem->text().toStdString();
}

