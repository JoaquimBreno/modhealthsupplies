#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <cadastro.h>
#include <table.h>
#include <consultanomeinsumo.h>
#include <consultalocal.h>
#include <consultalocalportipo.h>
#include <consultainsumo.h>
#include <controler.h>
#include <storagemanager.h>
#include <QMainWindow>
#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Controler ct;
    storagemanager st;
    ~MainWindow();

private slots:
    void on_actionCadastrar_Insumo_triggered();

    void on_actionConsulta_Insumos_triggered();

    void on_actionConsulta_por_Tipo_triggered();

    void on_actionConsulta_Descri_o_triggered();

    void on_actionConsulta_Descri_o_Por_Local_triggered();

    void on_actionDistribuir_Insumo_triggered();

    void on_actionSalvar_em_Arquivo_triggered();

    void on_actionSobre_n_s_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
