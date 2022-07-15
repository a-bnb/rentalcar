#include "mainpage.h"
#include "ui_mainpage.h"
#include "content.h"
#include "signup.h"
#include "member.h"
#include "database.h"
#include "user.h"
#include "contdata.h"
#include "reservation.h"
#include "rentalcar_.h"
#include "rentalcar.h"
#include "login.h"
#include "chat.h"

mainpage::mainpage(tcp sock, QString ty, QString re, QString co, QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainpage),
    sock(sock),
    re(re),
    co(co),
    ty(ty),
    id(id)
{
    ui->setupUi(this);
}

mainpage::~mainpage()
{
    delete ui;
}

void mainpage::on_userPush_clicked()
{
    this->hide();
    member u(id, db);
    u.setModal(true);
    u.exec();
    this->show();

}

void mainpage::on_contentPush_clicked()
{
    this->hide();
    content c(co, db);
    c.setModal(true);
    c.exec();
    this->show();
}

void mainpage::on_rentalPush_clicked()
{
    this->hide();
    rentalcar r(re, db);
    r.setModal(true);
    r.exec();
    this->show();
}


/*void mainpage::on_Reserv_Push_clicked()
{
    this->hide();
    reservation y(ty, db);
    y.setModal(true);
    y.exec();
    this->show();
}*/

void mainpage::on_chat_btn_clicked()
{
    sql_query.exec("SELECT username FROM user WHERE userid='"+id+"'");
    sql_query.next();
    QString name = sql_query.value(0).toString();
    chat r(name, sock,db);
    r.setModal(true);
    r.exec();
    this->show();
}
