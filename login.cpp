#include "login.h"
#include "ui_login.h"
#include "signup.h"
#include "content.h"
#include "mainpage.h"
#include "rentalcar.h"
#include "reservation.h"

using namespace std;

login::login( Database db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    this->db = db;
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_login_btn_clicked()
{
    QString id = ui->ID_text->text();
    QString pw = ui->PW_text->text();


    if(id == "" || pw == "")
    {
        QMessageBox::information(this, "error", "공백");
    }
    else
    {

        sprintf(query, "SELECT userpw, username FROM user where userid='%s'", id.toLocal8Bit().data());
        sql_query.exec(QString::fromLocal8Bit(query));
        if(sql_query.size() == 0)
        {
            QMessageBox::warning(this, "login failed", "");

        }
        else
        {
            sql_query.next();
            if(sql_query.value(0) != pw)
            {
                QMessageBox::warning(this, "error", "PW error");
            }
            else
            {
                this->close(); // 기존 창 닫기
                tcp sock;
                sock.connect_server();
                mainpage userWindow(sock, ty,re,co,id); // 객체 생성
                userWindow.setModal(true); // 정보찾기창 열기
                userWindow.exec(); // 정보찾기창 닫으면
                this->show();
                 /*this->close();
                 beach_ b(db);
                 b.setModal(true);
                 b.exec();
                 this->show();*/
            }
        }

    }
}

void login::on_signup_btn_clicked()
{
    this->hide();
    signup signup(db);
    signup.setModal(true);
    signup.exec();
    this->show();
}

void login::on_exit_btn_clicked()
{
    exit(0);
}
