#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "commande.h"
#include "lista.h"
#include "login.h"
#include <QString>
#include <QMainWindow>

#include <QtWidgets/QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void display_other_items();

public slots:
    //void on_pushButton_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    //void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_4_activated(const QString &arg1);



    void on_comboBox_3_activated(const QString &arg1);



    void on_comboBox_5_activated(const QString &arg1);



    void on_comboBox_6_activated(const QString &arg1);



    void on_comboBox_7_activated(const QString &arg1);


    void on_ComboBox_2_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
private:
    Ui::MainWindow *ui;

     Commande tmpcommande;
     lista *listas;

};

#endif // MAINWINDOW_H
