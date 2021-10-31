#include "commande.h"
#include <QDebug>
#include <QSqlRecord>
Commande::Commande()
{

}
Commande::Commande(QString Pizza,QString Lasagne,QString Pasta,QString Dessert,QString Drinks)
{
  this->Pizza=Pizza;
    this->Lasagne=Lasagne;
    this->Pasta=Pasta;
    this->Dessert=Dessert;
    this->Drinks=Drinks;

}
QString Commande::get_Pizza(){return  Pizza;}
QString Commande::get_Status(){return  Status;}
QString Commande::get_Pizza_Size(){return  Pizza_Size;}
QString Commande::get_Lasagnee(){return  Lasagne;}
QString Commande::get_Pasta(){return  Pasta;}
QString Commande::get_Dessert(){return  Dessert;}
QString Commande::get_Drinks(){return  Drinks;}
int Commande::get_id(){return  id;}
float Commande::get_Price(){return Price;}

bool Commande::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res2= QString::number(Price);
    query.prepare("INSERT INTO Commande (ID,PIZZA,PIZZA_SIZE,LASAGNE,PASTA,DESSERT,DRINKS,PRICE,STATUS) VALUES (:id, :Pizza, :Pizza_Size, :Lasagne, :Pasta, :Dessert, :Drinks, :Price, :Status)");
    query.bindValue(":id", res);
    query.bindValue(":Pizza", Pizza);
    query.bindValue(":Pizza_Size", Pizza_Size);
    query.bindValue(":Lasagne", Lasagne);
    query.bindValue(":Pasta", Pasta);
    query.bindValue(":Dessert", Dessert);
    query.bindValue(":Drinks", Drinks);
    query.bindValue(":Price", res2);
    query.bindValue(":Status", Status);


    return    query.exec();
}


QSqlQueryModel * Commande::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    QSqlQuery query("select * from Commande");

    query.exec();

    model->setQuery(query);

    return model;
}
bool Commande::modifier(int a, QString b){
    QSqlQuery query;
    QString res= QString::number(a);
    query.prepare("update commande set status=:status where id = :id;");
    query.bindValue(":id", res);
    query.bindValue(":status", b);


    return query.exec();
}
QSqlQueryModel * Commande::afficher_prix()
{QSqlQueryModel * model= new QSqlQueryModel();

QSqlQuery query("SELECT SUM(PRICE) AS EARNINGS from Commande");

 query.exec();

 model->setQuery(query);




    return model;
}


