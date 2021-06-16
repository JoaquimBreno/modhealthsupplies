#include "cadastroepi.h"
#include "ui_cadastroepi.h"
#include <QPixmap>

cadastroepi::cadastroepi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastroepi)
{
    setWindowTitle("Cadastro Epi");
    ui->setupUi(this);
    QPixmap pix(":/src/src/white.png");
    ui->label_7->setPixmap((pix.scaled(900,800,Qt::KeepAspectRatio)));
}

cadastroepi::~cadastroepi()
{
    delete ui;
}

std::string cadastroepi::getTipo()
{
    return tipo;
}

std::string cadastroepi::getAtDescricao()
{
    return descricao;
}

void cadastroepi::on_buttonBox_accepted()
{
    this->tipo = ui->tipo->text().toStdString();
    this->descricao = ui->atdescricao->text().toStdString();

}

