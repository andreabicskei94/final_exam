#include "sales.h"
#include "ui_sales.h"
#include <QMessageBox>

sales::sales(QWidget *parent) :
    QWidget(parent),
    ui(new  Ui::sales)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::database("SQLITE");

    QSqlQuery qry(db);

    if (qry.prepare("SELECT * FROM sales"))
    {

        qry.exec();
        int numRows=1;
        int numColumns=5;
        ui->tableWidget->setColumnCount(numColumns);

        while(qry.next())
        {
            ui-> tableWidget->insertRow ( ui->tableWidget->rowCount() );

            for (auto c=0; c<numColumns; c++)
            {
                QString val=qry.value(c).toString();
                 ui->tableWidget->setItem( ui->tableWidget->rowCount()-1, c, new QTableWidgetItem(val));
            }
            numRows++;

        }
    }
    this->show();

}

//Destructor
sales::~sales()
{
    delete ui;
}

//On back button click go to admin dashboard
void sales::on_back_clicked()
{
    adminpannel * myadminpannel=new adminpannel();
    this->hide();
    delete this;

}

