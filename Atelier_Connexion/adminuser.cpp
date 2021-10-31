#include "adminuser.h"
#include "ui_adminuser.h"
#include <QMessageBox>

admin_user_panel::admin_user_panel(QWidget *parent) :
    QWidget(parent),
    ui(new  Ui::adminuser)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::database("SQLITE");

    QSqlQuery qry(db);
//Get list of all logins
    if (qry.prepare("SELECT * FROM LOGIN"))
    {

        qry.exec();
        int numRows=1;
        int numColumns=3;
        ui->tableWidget->setColumnCount(numColumns);

        while(qry.next())
        {
            //If another row exists add a new row to table
            ui-> tableWidget->insertRow ( ui->tableWidget->rowCount() );

            for (auto c=0; c<numColumns; c++)
            {
                QString val=qry.value(c).toString();
                //Assign query column results to table column
                 ui->tableWidget->setItem( ui->tableWidget->rowCount()-1, c, new QTableWidgetItem(val));
            }
            numRows++;

        }
    }
    this->show();

}


admin_user_panel::~admin_user_panel()
{
    delete ui;
}
//In case of add a row just add a row on table of widget

void admin_user_panel::on_AddUserRecord_clicked()
{
    ui-> tableWidget->insertRow ( ui->tableWidget->rowCount());
}

//In case of delete a row just delete a row on table of widget

void admin_user_panel::on_DeleteUserRecord_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}


void admin_user_panel::on_SaveButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database("SQLITE");

    QSqlQuery qry(db);
    //Delete all rows from login table so we can add modified rows i.e. password or user modified
    if (qry.prepare("Delete FROM LOGIN"))
    {
        qry.exec();
        for(auto r=0;r<ui->tableWidget->rowCount();r++)
        {
            //Run insert query
            qry.prepare("INSERT INTO login (username,pass,role) "
                              "VALUES (:un, :pwd,:role)");
            QString val=ui->tableWidget->item(r,0)->text();
            //bind value to get  values from user
            qry.bindValue(":un",val);
            qry.bindValue(":pwd",ui->tableWidget->item(r,1)->text());
            qry.bindValue(":role",ui->tableWidget->item(r,2)->text());
    //Execute query
                bool test =qry.exec();
                if(!test)
                {
                    qDebug("Error occurred inserting.");
                    qDebug("%s.", qPrintable(qry.lastError().text()));
                    qDebug("%s.", qPrintable(qry.executedQuery()));


                }
        }
        QMessageBox::critical(nullptr, QObject::tr("Success"),
                                       QObject::tr("User Updated Succesfully.\n"
                               ), QMessageBox::Ok);
        this->hide();


    }
    else{
        qDebug("Error occurred inserting.");
        qDebug("%s.", qPrintable(qry.lastError().text()));
        qDebug("%s.", qPrintable(qry.executedQuery()));

    }
}

//On back button click go to admin dashboard
void admin_user_panel::on_BackButton_clicked()
{
    adminpannel * myadminpannel=new adminpannel();
    this->hide();
    delete this;
}

