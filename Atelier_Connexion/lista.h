#ifndef LISTA_H
#define LISTA_H

#include <QWidget>
#include "commande.h"
#include "payment.h"
#include "login.h"
#include "newlogin.h"

namespace Ui {
class lista;
}

class lista : public QWidget
{
    Q_OBJECT

public:
    explicit lista(QWidget *parent = nullptr);
    ~lista();

private slots:
    void on_pushButton_clicked();



    void on_pushButton_2_clicked();

private:
    Ui::lista *ui;
    Commande tmpcom;
    payment *pay;
    login *logins;
    newlogin *newlogins;
};

#endif // LISTA_H
