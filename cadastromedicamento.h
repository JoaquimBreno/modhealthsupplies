#ifndef CADASTROMEDICAMENTO_H
#define CADASTROMEDICAMENTO_H

#include <QDialog>

namespace Ui {
class cadastromedicamento;
}

class cadastromedicamento : public QDialog
{
    Q_OBJECT

public:
    explicit cadastromedicamento(QWidget *parent = nullptr);
    std::string getDosagem();
    std::string getAdministracao();
    std::string getDisponibilizacao();
    ~cadastromedicamento();

protected:
    std::string dosagem;
    std::string administracao;
    std::string disponibilizacao;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::cadastromedicamento *ui;
};

#endif // CADASTROMEDICAMENTO_H
