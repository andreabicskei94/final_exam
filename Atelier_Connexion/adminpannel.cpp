#include "adminuser.h"
#include "adminproduct.h"
#include "sales.h"
#include "ui_adminpannel.h"
#include "login.h"

#include <QMessageBox>

//Pointer to each button admin pannel
admin_user_panel *admin_user_view;
adminproduct * admin_product_view;
sales * admin_sales_view;


//Initialize constructor for Admin Pannel
adminpannel::adminpannel(QWidget *parent) :
    QWidget(parent),

    ui(new  Ui::adminpannel)
{
    ui->setupUi(this);
    //Show admin pannel Qwidget on initialization
    this->show();


}


adminpannel::~adminpannel()
{
    delete ui;
}




//On User Button click show user screen
void adminpannel::on_userButton_clicked()
{

    admin_user_view=new admin_user_panel();
    this->hide();
    //Delete this so that memoryleak is avoided
    delete this;

}

//On Product Button click show Product list screen

void adminpannel::on_productsButton_clicked()
{
    admin_product_view=new adminproduct();
    //Hide current window
    this->hide();
    //Delete this so that memoryleak is avoided

    delete this;

}


//On Sales Button click show current Sales screen
void adminpannel::on_salesButton_clicked()
{
    admin_sales_view=new sales();
    //Hide current window

    this->hide();
    //Delete this so that memoryleak is avoided

    delete this;

}

//If logout go back to login screen
void adminpannel::on_logoutButton_clicked()
{
    login *nl=new login();
    nl->show();
    //Hide current window
    this->hide();
    //Delete this so that memoryleak is avoided
    delete this;
}

