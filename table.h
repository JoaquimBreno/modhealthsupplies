#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include "insumo.h"
#include "vacina.h"
#include "medicamento.h"
#include "epi.h"
#include <vector>
#include <string>

namespace Ui {
class table;
}

class table : public QDialog
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = nullptr);
    void setInsumo(std::vector<Insumo*> insumos, int tipoInsumo);
    ~table();
private:
    Ui::table *ui;
};

#endif // TABLE_H
