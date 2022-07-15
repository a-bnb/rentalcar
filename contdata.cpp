#include "contdata.h"
#include "ui_contdata.h"
#include "database.h"

contdata::contdata(Database db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contdata)
{
    this->db = db;
    ui->setupUi(this);
}

contdata::~contdata()
{
    delete ui;
}

void contdata::on_contdataButton1_clicked()
{
    sprintf(query, "SELECT * FROM content");
    sql_query.exec(QString::fromLocal8Bit(query)); // fromLocal8Bit 한글꺠짐 해결 방법
    sql_query.first();
    while(sql_query.next())
    {
       ui->textBrowser1->append(sql_query.value(0).toString());

    }
}


void contdata::on_contdataButton2_clicked()
{
     this->close();
}
