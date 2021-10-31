#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

#include "login.h"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login nl;
    Connection c;
    bool test = c.createconnect();
    if(test)
    {
        nl.show();


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                       QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
