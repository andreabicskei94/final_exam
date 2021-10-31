#ifndef ADMINUSER_H
#define ADMINUSER_H


#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QFileInfo>
#include <payment.h>
#include "adminpannel.h"
#include "connection.h"
namespace Ui {
class adminuser;
}

class admin_user_panel : public QWidget
{
    Q_OBJECT

public:
    explicit admin_user_panel(QWidget *parent = nullptr);
    ~admin_user_panel();

private slots:



    void on_AddUserRecord_clicked();

    void on_DeleteUserRecord_clicked();

    void on_SaveButton_clicked();

    void on_BackButton_clicked();

private:
    Ui::adminuser *ui;
};

#endif // ADMINUSER_H
