#include "adminproduct.h"
#include "ui_adminproduct.h"
#include <QMessageBox>


//Constructor
adminproduct::adminproduct(QWidget *parent) :
    QWidget(parent),
    ui(new  Ui::adminproduct)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::database("SQLITE");

    QSqlQuery qry(db);
    //Get all products from DB and show it in table widget
    if (qry.prepare("SELECT * FROM products"))
    {

        qry.exec();
        int numRows=1;
        int numColumns=5;//no of columns
        ui->tableWidget->setColumnCount(numColumns);

        while(qry.next())
        {
            //Insert a new row if we have another row in query result
            ui-> tableWidget->insertRow ( ui->tableWidget->rowCount() );

            for (auto c=0; c<numColumns; c++)
            {
                QString val=qry.value(c).toString();
                //Assign all columns to table rows
                 ui->tableWidget->setItem( ui->tableWidget->rowCount()-1, c, new QTableWidgetItem(val));
            }
            numRows++;

        }
    }
    this->show();

}

//Destructor

adminproduct::~adminproduct()
{
    delete ui;
}

//In case of add a row just add a row on table of widget

void adminproduct::on_AddProductRecord_clicked()
{
    ui-> tableWidget->insertRow ( ui->tableWidget->rowCount());
}




//In case of delete a row just delete a row on table of widget
void adminproduct::on_DeleteProductRecord_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}


void adminproduct::on_saveButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database("SQLITE");

    QSqlQuery qry(db);

    if (qry.prepare("Delete FROM products"))
    {
        qry.exec();
        for(auto r=0;r<ui->tableWidget->rowCount();r++)
        {
            //Insert into product table the values entered in the UI so that a new product is created.
            qry.prepare("INSERT INTO products (Id,Name,Qty,Category,price) "
                              "VALUES (:id, :nm,:qty,:ctgry,:price)");
            QString val=ui->tableWidget->item(r,0)->text();
            qry.bindValue(":id",val);
            qry.bindValue(":nm",ui->tableWidget->item(r,1)->text());
            qry.bindValue(":qty",ui->tableWidget->item(r,2)->text().toInt());
            qry.bindValue(":ctgry",ui->tableWidget->item(r,3)->text());
            qry.bindValue(":price",ui->tableWidget->item(r,4)->text().toInt());


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


void adminproduct::on_back_clicked()
{
   adminpannel * myadminpannel=new adminpannel();
   //hide current screen
    this->hide();
   //avoid memory leakage
    delete this;
}

