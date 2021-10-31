#include "userdashboard.h"
#include "ui_userdashboard.h"
#include "login.h"

#include <QMessageBox>
userdashboard::userdashboard(QWidget *parent) :
    QWidget(parent),
    ui(new  Ui::userdashboard)
{
    ui->setupUi(this);
    ui->checkOutButton->hide();

    QSqlDatabase db = QSqlDatabase::database("SQLITE");

    QSqlQuery qry(db);

    if (qry.prepare("SELECT * FROM products"))
    {

        qry.exec();
        int numRows=1;
        int numColumns=5;
        ui->tableWidget->setColumnCount(numColumns);

        while(qry.next())
        {
            ui-> tableWidget->insertRow ( ui->tableWidget->rowCount() );
            if(qry.value(2).toInt()>0){
                for (auto c=0; c<numColumns; c++)
                {
                    QString val=qry.value(c).toString();
                     ui->tableWidget->setItem( ui->tableWidget->rowCount()-1, c, new QTableWidgetItem(val));
                }
            }
            ui->tableWidget->setItem( ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem("1"));

            numRows++;

        }
    }
    this->show();


}


userdashboard::~userdashboard()
{
    delete ui;
}




void userdashboard::on_AddCartButton_clicked()
{
    int curr_row=ui->tableWidget->currentRow();
    QSqlDatabase db = QSqlDatabase::database("SQLITE");

    QSqlQuery qry(db);

    if (qry.prepare("SELECT qty FROM products where Id=:id"))
    {

        qry.bindValue(":id",ui->tableWidget->item(curr_row,0)->text());
        qry.exec();
    }
    qry.next();
    int curr_qty=qry.value(0).toInt();
    int order_qty=ui->tableWidget->item(curr_row,2)->text().toInt();
    if(curr_qty>order_qty && order_qty!=0){
        Items.push_back(ui->tableWidget->item(curr_row,0)->text());
        quantity.push_back(order_qty);
        Name.push_back(ui->tableWidget->item(curr_row,1)->text());
        Category.push_back(ui->tableWidget->item(curr_row,3)->text());
        Price.push_back(ui->tableWidget->item(curr_row,4)->text().toInt());

        QMessageBox::critical(nullptr, QObject::tr("Item Added Succesfully"),
                                       QObject::tr("Press OK to Continue"
                                                  ),
                              QMessageBox::Ok);
    }
    else{
        QString str1=qry.value(2).toByteArray();
        QByteArray ba = str1.toLocal8Bit();
        const char *c_str2 = ba.data();


        QMessageBox::critical(nullptr, QObject::tr("Item Not Available"),
                                       QObject::tr("Max quantity Available is: ",c_str2
                                                  ),
                              QMessageBox::Ok);
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}


void userdashboard::on_CartButton_clicked()
{
    int total_price=0;
    ui->CartButton->hide();
    ui->AddCartButton->hide();
    ui->tableWidget->clearContents();
    ui->checkOutButton->show();
    for (auto rows=0; rows<Items.size(); rows++)
    {
        ui->tableWidget->setItem( rows, 0, new QTableWidgetItem(Items[rows]));
        ui->tableWidget->setItem( rows, 1, new QTableWidgetItem(Name[rows]));
        ui->tableWidget->setItem( rows, 2, new QTableWidgetItem(QString::number(quantity[rows])));
        ui->tableWidget->setItem( rows, 3, new QTableWidgetItem(Category[rows]));
        ui->tableWidget->setItem( rows, 4, new QTableWidgetItem(QString::number(Price[rows])));
        total_price=total_price+quantity[rows]*Price[rows];

    }
    QString myBill="Total Bill: "+ QString::number(total_price)+" $";
    ui->lineEdit->setText(myBill);
    my_total_price=total_price;

}


void userdashboard::on_checkOutButton_clicked()
{


    pymnt=new checkout();
    pymnt->setPrice (my_total_price);
    this->hide();

    pymnt->show();
}

//In case of remove a row just remove a row on table of widget

void userdashboard::on_RemoveButton_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());

}


void userdashboard::on_logOutButton_clicked()
{
    login *nl=new login();
    nl->show();
    this->hide();
    delete this;
}

