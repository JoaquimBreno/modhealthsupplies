#ifndef CADASTRO_H
#define CADASTRO_H
#include <vector>
#include <iostream>
#include <cadastrovacina.h>
#include <cadastromedicamento.h>
#include <cadastroepi.h>

#include "mainwindow.h"
#include "vacina.h"
#include "insumo.h"
#include "epi.h"
#include "medicamento.h"
#include "controler.h"
#include "locais.h"
#include <QDialog>

namespace Ui {
class cadastro;
}

class cadastro : public QDialog
{
    Q_OBJECT

public:
    explicit cadastro(QWidget *parent = nullptr);
    Insumo* getInsumo();
    ~cadastro();
protected:
    Insumo* ins;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::cadastro *ui;
};

#endif // CADASTRO_H
