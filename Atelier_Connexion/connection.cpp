#include "connection.h"
//DB connection at start and initialize if empty
Connection::Connection()
{

}

bool Connection::createconnect(){
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE","SQLITE");
    //Db name to set connection too
    db.setDatabaseName("storedb.db");

    if(db.open()){
        qDebug() << "Database Connected!";

    }
    QSqlQuery sql(db);
    if(db.isValid()){
        //If db is connected first time add important data for config i.e. tables and login
        if(db.tables().isEmpty()){
            // Create all table
            sql.exec("CREATE TABLE \"login\" ( 'username' TEXT NOT NULL, 'pass' TEXT NOT NULL, 'role' TEXT NOT NULL)");
            sql.exec("CREATE TABLE \"products\" ( 'Id' TEXT NOT NULL, 'Name' TEXT NOT NULL,'Qty' INTEGER NOT NULL, 'Category' TEXT NOT NULL,'price' INTEGER NOT NULL)");
            sql.exec("CREATE TABLE \"sales\" ( 'OrderId' TEXT NOT NULL, 'Name' TEXT NOT NULL, 'MobileNumber' TEXT NOT NULL, 'Address' TEXT NOT NULL,'Totalprice' INTEGER NOT NULL)");
            //Insert admin role
            sql.prepare("INSERT INTO login (username,pass,role) "
                              "VALUES (:un, :pwd,:role)");
            sql.bindValue(":un","admin");
            sql.bindValue(":pwd","12345");
            sql.bindValue(":role","admin");
            sql.exec();
            qDebug() <<sql.numRowsAffected();
            if(sql.numRowsAffected() == 1) {
                qDebug() << "Database Created!";
            }
            else{

                qDebug("%s.", qPrintable(sql.lastError().text()));
                qDebug("%s.", qPrintable(sql.executedQuery()));
            }
            return true;
        }
        return true;
    }

    return  true;
}
