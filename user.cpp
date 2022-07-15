#include "user.h"
#include "ui_user.h"
#include "database.h"

user::user(Database db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user)
{
    this->db = db;
    ui->setupUi(this);
}

user::~user()
{
    delete ui;
}

void user::on_inquiry1_clicked()
{
    sprintf(query, "SELECT * FROM user");
    sql_query.exec(QString::fromLocal8Bit(query)); // fromLocal8Bit 한글꺠짐 해결 방법
    sql_query.first();
    while(sql_query.next())
    {
       ui->textBrowser->append(sql_query.value(0).toString());

    }
}


void user::on_exit_btn_clicked()
{
     this->close();
}
