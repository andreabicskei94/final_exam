#ifndef ADMINPRODUCT_H
#define ADMINPRODUCT_H



#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QFileInfo>
#include <payment.h>
#include "connection.h"
#include "adminpannel.h"

namespace Ui {
class adminproduct;
}

class adminproduct : public QWidget
{
    Q_OBJECT

public:
    explicit adminproduct(QWidget *parent = nullptr);
    ~adminproduct();

private slots:





    void on_AddProductRecord_clicked();

    void on_DeleteProductRecord_clicked();

    void on_saveButton_clicked();

    void on_back_clicked();

private:
    Ui::adminproduct *ui;
};


#endif // ADMINPRODUCT_H
