#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QFileInfo>
#include <payment.h>
#include "connection.h"
#include <vector>
namespace Ui {
class checkout;
}
class checkout : public QWidget
{
    Q_OBJECT

public:
    explicit checkout(QWidget *parent = nullptr,int total_price=0);
    void setPrice(int total_price);
    ~checkout();
private slots:
    void on_ConfirmButton_clicked();

    void on_CartButton_clicked();

private:
    Ui::checkout *ui;
    int my_price;
};

#endif // CHECKOUT_H
