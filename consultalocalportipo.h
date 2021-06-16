#ifndef CONSULTALOCALPORTIPO_H
#define CONSULTALOCALPORTIPO_H

#include <QDialog>

namespace Ui {
class consultalocalportipo;
}

class consultalocalportipo : public QDialog
{
    Q_OBJECT

public:
    explicit consultalocalportipo(QWidget *parent = nullptr);
    int getTipo();
    int getTipodoLocal();
    ~consultalocalportipo();
protected:
    int tipo;
    int local;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::consultalocalportipo *ui;
};

#endif // CONSULTALOCALPORTIPO_H
