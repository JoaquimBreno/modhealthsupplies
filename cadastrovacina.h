#ifndef CADASTROVACINA_H
#define CADASTROVACINA_H
#include <QDialog>

namespace Ui {
class cadastrovacina;
}

class cadastrovacina : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrovacina(QWidget *parent = nullptr);
    std::string getTipoVac();
    int getQuantDoses();
    int getIntervalo();

    ~cadastrovacina();

protected:
    std::string tipoVac;
    int quantDoses;
    int intervalo;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::cadastrovacina *ui;

};

#endif // CADASTROVACINA_H
