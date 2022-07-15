#include "member.h"
#include "ui_member.h"
#include "user.h"
#include "signup.h"
#include "database.h"
#include "login.h"

member::member(QString id, Database db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::member),
    id(id)
{
    this->db = db;
    ui->setupUi(this);
    //ui->setupUi(this);
    //this->Get_id = Get_id;
}

member::~member()
{
    delete ui;
}

void member::on_userinquiry_clicked() //회원 조회
{
    int column, i;
    QString temp;
    ui->user_table->clearContents();
    std::cout<<id.toStdString()<<std::endl;
    sprintf(query, "SELECT * FROM user WHERE userid ='%s'", id.toLocal8Bit().data());
    sql_query.exec(QString::fromLocal8Bit(query)); // QString 변경
    ui->user_table->setRowCount(sql_query.size());
    column = sql_query.record().count();
    if(sql_query.lastError().type() != QSqlError::NoError)
    {
        std::cout<<sql_query.lastError().text().toStdString()<<std::endl;
    }

    sql_query.next(); // db 데이터에 다음을 표기
    for(i=0; i<column; i++)
    {
        ui->user_table->setItem(0, i, new QTableWidgetItem(sql_query.value(i).toString()));
    }
    ui->user_table->show();
}

void member::on_userrectified_clicked() //회원 수정
{
    QString column = ui->user_table->takeHorizontalHeaderItem(selected)->text();
    QString change = ui->edit_text->text();
    sprintf(query, "UPDATE user SET %s = '%s' WHERE userid='%s'",column.toLocal8Bit().data(), change.toLocal8Bit().data(), id.toLocal8Bit().data());
    sql_query.exec(QString::fromLocal8Bit(query));
    if(sql_query.lastError().type() == QSqlError::NoError)
    {
        QMessageBox::information(this, "message", "change Complete!");
    }
    else
    {
        QMessageBox::information(this, "error", "변경 실패");
    }
    //sql_query.next();
    this->on_userinquiry_clicked();
}

void member::on_userescape_clicked() //회원 탈퇴
{
   sprintf(query, "select * FROM user WHERE userid='%s'", id.toLocal8Bit().data());
   sql_query.exec(QString::fromLocal8Bit(query));
   if(sql_query.lastError().type() != QSqlError::NoError)
   {
       QMessageBox::information(this, "error", "삭제 실패");
       return;
   }
   sprintf(query, "DELETE FROM user WHERE userid='%s'", id.toLocal8Bit().data());
   sql_query.exec(QString::fromLocal8Bit(query));
   if(sql_query.lastError().type() == QSqlError::NoError)
   {
       QMessageBox::information(this, "message", "Delete Complete!");
       this->close();
   }
   else
   {
       QMessageBox::information(this, "error", "삭제 실패");
   }
   exit(0);
}

void member::on_user_table_itemClicked(QTableWidgetItem *item)
{
    ui->edit_text->setText(item->text());
    selected = item->column();

}
