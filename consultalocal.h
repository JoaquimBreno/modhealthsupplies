#ifndef CONSULTALOCAL_H
#define CONSULTALOCAL_H
#include <mainwindow.h>
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class consultalocal;
}

class consultalocal : public QDialog
{
    Q_OBJECT

public:
    explicit consultalocal(QWidget *parent = nullptr);
    int getTipo();
    void iniciaConsulta(int tipo);
    ~consultalocal();

protected:
    int tipo;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::consultalocal *ui;
};

#endif // CONSULTALOCAL_H
