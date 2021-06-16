#ifndef CONSULTAINSUMO_H
#define CONSULTAINSUMO_H

#include <QDialog>
#include <vector>
#include <string>

namespace Ui {
class consultainsumo;
}

class consultainsumo : public QDialog
{
    Q_OBJECT

public:
    explicit consultainsumo(QWidget *parent = nullptr);
    void setVetorInsumos(std::vector<std::string>insumos);
    ~consultainsumo();

private:
    Ui::consultainsumo *ui;
};

#endif // CONSULTAINSUMO_H
