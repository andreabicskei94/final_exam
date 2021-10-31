#ifndef COMMANDE_H
#define COMMANDE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Commande
{
public:
    Commande();
    Commande(QString,QString,QString,QString,QString);
    int get_id();
    bool add();
    QString get_Pizza();
     QString get_Pizza_Size();
    QString get_Lasagnee();
    QString get_Pasta();
    float get_Price();
    QString get_Dessert();
    QString get_Status();
    QString get_Drinks();
    void set_id(int id){this->id=id;}
    void set_Pizza(QString Pizza){this->Pizza=Pizza;}
    void set_Pizza_Size(QString Pizza_Size){this->Pizza_Size=Pizza_Size;}
    void set_Lasagne(QString Lasagne){this->Lasagne=Lasagne;}
    void set_Pasta(QString Pasta){this->Pasta=Pasta;}
    void set_Dessert(QString Dessert){this->Dessert=Dessert;}
    void set_Drinks(QString Drinks){this->Drinks=Drinks;}
    void set_Price(float Price){this->Price=Price;}
    void set_Status(QString Status){this->Status=Status;}
bool ajouter();
QSqlQueryModel * afficher();
QSqlQueryModel * afficher_prix();
bool modifier(int,QString);

private:
    int id;
    QString Pizza;
    QString Pizza_Size;
    QString Lasagne;
    QString Pasta;
    QString Dessert;
    QString Drinks;
    QString Status;
    float Price;
};

#endif // COMMANDE_H
