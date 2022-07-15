#include "signup.h"
#include "ui_signup.h"

signup::signup(Database db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    this->db = db;
    check = false;

    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}


void signup::on_check_btn_clicked()
{
    QString id = ui->ID_text->text();
    if(id == "")
    {
        QMessageBox::information(this, "error", "공백");
        return;
    }
    sprintf(query, "SELECT * FROM user WHERE userid = '%s'", id.toLocal8Bit().data());
    sql_query.exec(QString::fromLocal8Bit(query));
    if(sql_query.size() == 0)
    {
        check = true;
        QMessageBox::information(this, "OK", "통과");
    }
    else
    {
        QMessageBox::information(this, "error", "중복");
    }
}

void signup::on_signup_btn_clicked()
{
    char type[100] = "normal";
    if(!check)
    {
        QMessageBox::information(this, "error", "중복확인");
        return;
    }
    QString id = ui->ID_text->text();
    QString pw = ui->PW_text->text();
    QString name = ui->Name_text->text();
    if(pw == "" || name == "")
        QMessageBox::information(this, "error", "공백");
    else
    {
        if(ui->PW_text->text() != ui->PW2_text->text())
            QMessageBox::information(this, "error", "비밀번호 불일치");
        else
        {
            sprintf(query, "INSERT INTO user(userid, userpw, username, usertype) VALUES('%s','%s','%s','%s')",
                    id.toLocal8Bit().data(), pw.toLocal8Bit().data(), name.toLocal8Bit().data(), type);
            sql_query.exec(QString::fromLocal8Bit(query));
            if(sql_query.size() == 0)
            {
                QMessageBox::information(this, "error", "데이터베이스 접근 오류");
            }
            else
            {
                QMessageBox::information(this, "축", "축) 가입");
                this->close();
            }

        }
    }

}

void signup::on_exit_btn_clicked()
{
    this->close();
}
