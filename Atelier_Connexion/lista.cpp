#include "lista.h"
#include "ui_lista.h"
//#include "ui_register.h"

#include <QDialog>
lista::lista(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lista)
{
    ui->setupUi(this);
    ui->tabcom->setModel(tmpcom.afficher());
    ui->tableView->setModel(tmpcom.afficher_prix());
}

lista::~lista()
{
    delete ui;
}

void lista::on_pushButton_clicked()
{

    logins =new login;
    logins->show();


}

void lista::on_pushButton_2_clicked()
{
    newlogins =new newlogin;
    newlogins->show();
}
