#ifndef ADMINPANNEL_H
#define ADMINPANNEL_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QFileInfo>
#include "connection.h"


namespace Ui {
class adminpannel;
}

class adminpannel : public QWidget
{
    Q_OBJECT

public:
    explicit adminpannel(QWidget *parent = nullptr);
    ~adminpannel();

private slots:


    void on_userButton_clicked();

    void on_productsButton_clicked();

    void on_salesButton_clicked();
    void on_logoutButton_clicked();



private:
    Ui::adminpannel *ui;

};


#endif // ADMINPANNEL_H
