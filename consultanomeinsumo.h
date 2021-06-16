#ifndef CONSULTANOMEINSUMO_H
#define CONSULTANOMEINSUMO_H

#include <QDialog>

namespace Ui {
class consultanomeinsumo;
}

class consultanomeinsumo : public QDialog
{
    Q_OBJECT

public:
    explicit consultanomeinsumo(QWidget *parent = nullptr);
    int getQuantidade();
    int getTipodoLocal();
    std::string getNome();
    ~consultanomeinsumo();
protected:
    int quantidade;
    int local;
    std::string nome;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::consultanomeinsumo *ui;
};

#endif // CONSULTANOMEINSUMO_H
