#ifndef CLIENT_H
#define CLIENT_H
#include "commande.h"
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class client
{
public:
    client();
    void set_id(int id){this->id=id;}
    void set_id_client(int id){this->client_id=id;}
    void set_name(QString id){this->name=id;}
    void set_street(QString id){this->street=id;}
    void set_hausnr(QString id){this->hausnr=id;}
    void set_zipcode(QString id){this->zipcode=id;}
    void set_number(QString id){this->cardnumber=id;}
    int get_id();
bool ajouter();
QSqlQueryModel * afficher_order();
private:
    int client_id,id;
    QString name;
    QString street;
    QString hausnr;
    QString zipcode;
    QString cardnumber;
};

#endif // CLIENT_H
