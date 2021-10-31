#ifndef SALES_H
#define SALES_H
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QFileInfo>
#include "adminpannel.h"

#include "connection.h"
namespace Ui {
class sales;
}

class sales : public QWidget
{
    Q_OBJECT

public:
    explicit sales(QWidget *parent = nullptr);
    ~sales();

private slots:




    void on_back_clicked();

private:
    Ui::sales *ui;
};



#endif // SALES_H
