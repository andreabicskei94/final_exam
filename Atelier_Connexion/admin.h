#ifndef ADMIN_H
#define ADMIN_H


#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QFileInfo>
#include <payment.h>
#include "connection.h"
namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:



private:
    Ui::admin *ui;
};


#endif // ADMIN_H
