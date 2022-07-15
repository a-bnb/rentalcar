#include "content.h"
#include "ui_content.h"
#include "database.h"
#include "login.h"
#include "signup.h"
#include "contdata.h"
#include "ui_contdata.h"

content::content(QString co, Database db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::content),
    co(co)
{
    this->db = db;
    ui->setupUi(this);
    this->on_contentyes_clicked();
}

content::~content()
{
    delete ui;
}

void content::on_contentyes_clicked()
{
    int column, i, line=0;
    QString temp;
    ui->content_screen->clearContents();
    std::cout<<co.toStdString()<<std::endl;
    sprintf(query, "SELECT * FROM content ORDER BY content_type");
    sql_query.exec(QString::fromLocal8Bit(query)); // QString 변경
    ui->content_screen->setRowCount(sql_query.size());
    column = sql_query.record().count();
    if(sql_query.lastError().type() != QSqlError::NoError)
    {
        std::cout<<sql_query.lastError().text().toStdString()<<std::endl;
    }

    sql_query.next(); // db 데이터에 다음을 표기
    if(sql_query.size() != 0)
       {
           while(sql_query.next())
           {
               for(i=0; i<column; i++)
               {
                   ui->content_screen->setItem(line, i, new QTableWidgetItem(sql_query.value(i).toString()));
               }
               line++;
           }
           ui->content_screen->show();

       }
    ui->content_screen->show();
}


void content::on_contentno_clicked()
{
    this->close();
}
