#include "client.h"

client::client()
{

}
int client::get_id(){return  id;}
bool client::ajouter()
{
QSqlQuery query;
QString res2= QString::number(id);
QString res= QString::number(client_id);

query.prepare("INSERT INTO client (CLIENT_ID,ID,NAME,HAUSNR,ZIPCODE,CARDNUMBER)"" VALUES (:client_id, :id, :name, :hausnr, :zipcode, :cardnumber)");
query.bindValue(":client_id", res);
query.bindValue(":id", res2);
query.bindValue(":name", name);


query.bindValue(":hausnr", hausnr);
query.bindValue(":zipcode", zipcode);
query.bindValue(":cardnumber", cardnumber);




return    query.exec();
}
QSqlQueryModel * client::afficher_order()
{QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery("select ID from commande");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;
}
