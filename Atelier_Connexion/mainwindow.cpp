#include "mainwindow.h"
#include "ui_mainwindow.h"



#include "commande.h"

#include <QDebug>
#include <QMessageBox>
#include <QDebug>
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <string.h>
#include <string>
#include <QDialog>

#include "QPixmap"
#include "QMessageBox"
#include "QPixmap"

#include <QPixmap>
#include <QSystemTrayIcon>

#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QtSql>
#include<QMap>
#include <iostream>
#include <QString>
#include<time.h>
#include <QTime>
#include <QDialog>
#include <qdialog.h>
#include <ctime>
#include<vector>
#include <QLineEdit>
#include <cstring>
#include <QSharedPointer>
#include<QSharedDataPointer>
//#include<qsharedpointer.h>
using namespace std;
//#include"qcustomplot.h"
#include "QPixmap"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Win10Pro/Downloads/edit/Atelier_Connexion/build-Atelier_Connexion-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/debug/maindb.db");

    ui->setupUi(this);
    ui->comboBox_2->clear();

    db.open();
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * queryplz = new QSqlQuery(db);
    queryplz->prepare("select [Name] from Main where Art = 'Pizza'");

    queryplz->exec();
    modal->setQuery(*queryplz);

    ui->comboBox_2->setModel(modal);



    ui->comboBox_8->clear();

    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QSqlQuery * queryplz2 = new QSqlQuery(db);
    queryplz2->prepare("select Price from Main");

    queryplz2->exec();
    modal2->setQuery(*queryplz2);

    ui->comboBox_8->setModel(modal2);
    db.close();

    ui->comboBox_3->clear();
    ui->comboBox_3->addItem("---");
    ui->comboBox_3->addItem("Lasagne Italiano");
    ui->comboBox_4->clear();
    ui->comboBox_4->addItem("---");
    ui->comboBox_4->addItem("Small");
    ui->comboBox_4->addItem("Medium");
    ui->comboBox_4->addItem("Large");
    QPixmap pix("C:/Users/User/Desktop/final.jpg");
    ui->label->setPixmap(pix);
    QPixmap pixmap("C:/Users/User/Desktop/BAZART/margherita.jpg");
    ui->label_2->setPixmap(pixmap);
    QPixmap pix2("C:/Users/User/Desktop/BAZART/tuna.jpg");
    ui->label_3->setPixmap(pix2);
    QPixmap pix3("C:/Users/User/Desktop/BAZART/crevette.jpg");
    ui->label_10->setPixmap(pix3);
    QPixmap pix4("C:/Users/User/Desktop/BAZART/quattro.jpg");
    ui->label_11->setPixmap(pix4);
    QPixmap pix5("C:/Users/User/Desktop/BAZART/water2.jpg");
    ui->label_12->setPixmap(pix5);
    QPixmap pix6("C:/Users/User/Desktop/BAZART/water.jpg");
    ui->label_13->setPixmap(pix6);
    QPixmap pix7("C:/Users/User/Desktop/BAZART/wine.jpg");
    ui->label_14->setPixmap(pix7);
    QPixmap pix8("C:/Users/User/Desktop/BAZART/coke.jpg");
    ui->label_15->setPixmap(pix8);
    QPixmap pix9("C:/Users/User/Desktop/BAZART/cokezero.jpg");
    ui->label_16->setPixmap(pix9);
    QPixmap pix10("C:/Users/User/Desktop/BAZART/beer.jpg");
    ui->label_17->setPixmap(pix10);
    QPixmap pix11("C:/Users/User/Desktop/BAZART/cotta.jpg");
    ui->label_18->setPixmap(pix11);
    QPixmap pix12("C:/Users/User/Desktop/BAZART/Tiramisu.jpg");
    ui->label_19->setPixmap(pix12);
    QPixmap pix13("C:/Users/User/Desktop/BAZART/carbonara.jpg");
    ui->label_20->setPixmap(pix13);
    QPixmap pix14("C:/Users/User/Desktop/BAZART/lasagne.jpg");
    ui->label_21->setPixmap(pix14);


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ComboBox_2_currentIndexChanged(int index)
{
//    ui->setupUi(this);
//    int currentindex = ui->comboBox_2->currentIndex();
//    QVariant variant = ui->comboBox_2->itemData(currentindex);
//    int fastfoodid = variant.toInt();
//    int fastfoodid = currentindex;

//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/Win10Pro/Downloads/edit/Atelier_Connexion/build-Atelier_Connexion-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/debug/maindb.db");

//    ui->setupUi(this);
//    ui->comboBox_8->clear();

//    db.open();
//    QSqlQueryModel * modal = new QSqlQueryModel();
//    QSqlQuery * queryplz = new QSqlQuery(db);
//    queryplz->prepare("select [Price] from Main");

//    queryplz->exec();
//    modal->setQuery(*queryplz);

//    ui->comboBox_8->setModel(modal);
//    db.close();
}
void MainWindow::on_comboBox_2_activated(const QString &arg1)
{

    tmpcommande.set_Pizza(arg1);

}


void MainWindow::on_comboBox_4_activated(const QString &arg1)
{
    tmpcommande.set_Pizza_Size(arg1);
}




void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    tmpcommande.set_Lasagne(arg1);
}


void MainWindow::on_comboBox_5_activated(const QString &arg1)
{
    tmpcommande.set_Pasta(arg1);
}


void MainWindow::on_comboBox_6_activated(const QString &arg1)
{
    tmpcommande.set_Dessert(arg1);
}


void MainWindow::on_comboBox_7_activated(const QString &arg1)
{
    tmpcommande.set_Drinks(arg1);
}


void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit->text().toInt();
    tmpcommande.set_id(id);
    tmpcommande.set_Price(0);
    tmpcommande.set_Status("Not purschased");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Win10Pro/Downloads/edit/Atelier_Connexion/build-Atelier_Connexion-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/debug/maindb.db");
    float price;

    db.open();

    QSqlQuery queryplz(db);
    queryplz.prepare("select Price from Main where [Name] ="+tmpcommande.get_Pizza());
    queryplz.exec();
    price = queryplz.value(0).toInt();
    tmpcommande.set_Price(tmpcommande.get_Price()+price);
    queryplz.clear();

    queryplz.prepare("select Price from Main where [Name] ="+tmpcommande.get_Lasagnee());
    queryplz.exec();
    price = queryplz.value(0).toInt();
    tmpcommande.set_Price(tmpcommande.get_Price()+price);
    queryplz.clear();

    queryplz.prepare("select Price from Main where [Name] ="+tmpcommande.get_Pasta());
    queryplz.exec();
    price = queryplz.value(0).toInt();
    tmpcommande.set_Price(tmpcommande.get_Price()+price);
    queryplz.clear();

    queryplz.prepare("select Price from Main where [Name] ="+tmpcommande.get_Dessert());
    queryplz.exec();
    price = queryplz.value(0).toInt();
    tmpcommande.set_Price(tmpcommande.get_Price()+price);
    queryplz.clear();

    queryplz.prepare("select Price from Main where [Name] ="+tmpcommande.get_Drinks());
    queryplz.exec();
    price = queryplz.value(0).toInt();
    tmpcommande.set_Price(tmpcommande.get_Price()+price);
    queryplz.clear();





    float s = tmpcommande.get_Price();
    bool test=tmpcommande.ajouter();
    if(test){//ui->tab->setModel(tmpcontrat.afficher());//refresh

        QMessageBox::information(nullptr, QObject::tr(" New command "),
                    QObject::tr("Comand Added.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("New command"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_2_clicked()
{

listas = new lista;
listas->show();



}
