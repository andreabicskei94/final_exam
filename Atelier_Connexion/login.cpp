#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

}


login::~login()
{
    delete ui;
}
void login::on_RegisterButton_clicked()
{
    QString username,password;
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();
    QSqlDatabase db = QSqlDatabase::database("SQLITE");

    QSqlQuery sql(db);
    //Insert into login table the new user created
    sql.prepare("INSERT INTO login (username,pass,role) "
                      "VALUES (:un, :pwd,:role)");
    sql.bindValue(":un",username);
    sql.bindValue(":pwd",password);
    sql.bindValue(":role","user");

        bool test =sql.exec();
        if(test)
            ui->label_3->setText("user registered succesfully please login");
        else
        {
            qDebug("Error occurred inserting.");
            qDebug("%s.", qPrintable(sql.lastError().text()));
            qDebug("%s.", qPrintable(sql.executedQuery()));
            qDebug() << sql.boundValue(":un");
            qDebug() << sql.boundValue(":pwd");

        }





}
void login::on_loginButton_clicked()
{
    QString username,password;
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();
    QSqlDatabase db = QSqlDatabase::database("SQLITE");

    QSqlQuery qry(db);

    if (qry.prepare("SELECT role FROM LOGIN WHERE username=\"" + username + "\"AND pass=\""  + password +"\""))
    {

        qry.exec();

        if(qry.next())
        {

            if(qry.value(0)=="admin"){
                qDebug() << "Admin Account";
//If admin role open admin pannel
                myadminpannel=new adminpannel();
                this->hide();

            }
            else{
                //If user role go to user dashboard
                myuserpannel=new userdashboard();
                this->hide();
                qDebug() <<"User Account";
            }

        }
        else
            ui->label_3->setText("username and password incorrect");
    }
}







