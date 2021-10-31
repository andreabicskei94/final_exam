#include "checkout.h"
#include "userdashboard.h"
#include "ui_checkout.h"
#include <QMessageBox>
//A random generator to use to generate order ID
std::string gen_random(const int len) {

    std::string tmp_s;
    //Alpha numeric order Id
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    srand( (unsigned) time(NULL) * getpid());

    tmp_s.reserve(len);
//Count till lenght
    for (int i = 0; i < len; ++i)
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];//Append a rand char from alphanum


    return tmp_s;

}
checkout::checkout(QWidget *parent,int total_price) :
    QWidget(parent),
    ui(new  Ui::checkout)
{
    //On check out hide the button generate a 16 digit random order number and find total bill
    ui->setupUi(this);
    std::string order_id= gen_random(16);
    QString myBill="OrderId: "+ QString::fromStdString(order_id);
    ui->OrderId->setText(myBill);

    my_price=total_price;

}
//Set the total price of the bill
void checkout::setPrice(int total_price){
    my_price=total_price;
}

checkout::~checkout()
{
    delete ui;
}




void checkout::on_ConfirmButton_clicked()
{
    QString name,address,mobile_numer;
    name=ui->Name->text();
    address=ui->Address->text();
    mobile_numer=ui->MobileNumber->text();

    QSqlDatabase db = QSqlDatabase::database("SQLITE");

    QSqlQuery sql(db);
    //As it is checkout so we need to save sale records to sale table so admin can view.

    sql.prepare("INSERT INTO sales (OrderId,Name,MobileNumber,Address,Totalprice) "
                      "VALUES (:Id, :Name,:MN,:Addr,:Tprice)");

    sql.bindValue(":Id",ui->OrderId->text());
    sql.bindValue(":Name",name);
    sql.bindValue(":MN",mobile_numer);
    sql.bindValue(":Addr",address);
    sql.bindValue(":Tprice",my_price);

        bool test =sql.exec();
        if(!test)
        {
            qDebug("Error occurred inserting.");
            qDebug("%s.", qPrintable(sql.lastError().text()));
            qDebug("%s.", qPrintable(sql.executedQuery()));


        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Order Success"),
                                           QObject::tr("Order has been Placed Succesfully.\n"
                                   ), QMessageBox::Ok);
            this->hide();
        }

}


void checkout::on_CartButton_clicked()
{
    userdashboard* myuserpannel=new userdashboard();
    //hide current windwo
    this->hide();

    //Delete to avoid memory leak
    delete this;
}

