#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QFileInfo>

class Connection
{
public:
    Connection();
    bool createconnect();
    void connclose();
    void connopen();
};

#endif // CONNECTION_H
