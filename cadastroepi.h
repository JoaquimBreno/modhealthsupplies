#ifndef CADASTROEPI_H
#define CADASTROEPI_H

#include <QDialog>

namespace Ui {
class cadastroepi;
}

class cadastroepi : public QDialog
{
    Q_OBJECT

public:
    explicit cadastroepi(QWidget *parent = nullptr);
    std::string getTipo();
    std::string getAtDescricao();
    ~cadastroepi();

protected:
    std::string tipo;
    std::string descricao;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::cadastroepi *ui;
};

#endif // CADASTROEPI_H
