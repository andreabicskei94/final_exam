#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QFileInfo>
#include <payment.h>
#include "connection.h"
#include "adminpannel.h"
#include "userdashboard.h"
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_RegisterButton_clicked();


    void on_loginButton_clicked();


private:
    Ui::login *ui;
    payment *pay;
    adminpannel *myadminpannel;
    userdashboard* myuserpannel;
};

#endif // LOGIN_H
