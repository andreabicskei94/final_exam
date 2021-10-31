#include "payment.h"
#include "ui_payment.h"
#include <QMessageBox>

#include <QSharedPointer>
payment::payment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::payment)
{
    ui->setupUi(this);
}

payment::~payment()
{
    delete ui;
}




void payment::on_pushButton_clicked()
{



            QString nom= ui->lineEdit->text();

            QString street= ui->lineEdit_2->text();
            QString hausnr= ui->lineEdit_3->text();
            QString zipcode= ui->lineEdit_4->text();
            QString number= ui->lineEdit_5->text();


          QMessageBox::information(nullptr, QObject::tr("Command"),
                            QObject::tr("Purschase sucessful\n"
                                        "Thank for your Review"), QMessageBox::Cancel);




        }

