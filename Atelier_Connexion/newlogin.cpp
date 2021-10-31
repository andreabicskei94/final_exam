#include "newlogin.h"
#include "ui_newlogin.h"
#include <QSqlQuery>
#include <QMessageBox>

newlogin::newlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newlogin)
{
    ui->setupUi(this);
}

newlogin::~newlogin()
{
    delete ui;
}

void newlogin::on_pushButton_clicked()
{
    QString username,password;
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();

    QSqlQuery query;

    if (query.prepare("INSERT INTO LOGIN (LOGIN,PWD) VALUES (:LOGIN, :PWD)"))
    {
        query.bindValue(":LOGIN", username);
        query.bindValue(":PWD", password);
bool test =query.exec();

if(test)
{
QMessageBox::information(nullptr, QObject::tr("Register Client"),
                QObject::tr("Client ADDED.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
hide();
}
else
    QMessageBox::critical(nullptr, QObject::tr("Register Client"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

}

