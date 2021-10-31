#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H




#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QFileInfo>
#include "checkout.h"
#include "connection.h"
#include <vector>

namespace Ui {
class userdashboard;
}

class userdashboard : public QWidget
{
    Q_OBJECT

public:
    explicit userdashboard(QWidget *parent = nullptr);
    ~userdashboard();

private slots:



    void on_AddCartButton_clicked();

    void on_CartButton_clicked();

    void on_checkOutButton_clicked();

    void on_RemoveButton_clicked();

    void on_logOutButton_clicked();

private:
    Ui::userdashboard *ui;
    checkout* pymnt;
    QVector<QString> Items;
    QVector<int>quantity;
    QVector<QString>Name;
    QVector<QString>Category;
    QVector<int>Price;
    int my_total_price;



};



#endif // USERDASHBOARD_H
