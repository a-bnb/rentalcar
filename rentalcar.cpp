#include "rentalcar.h"
#include "ui_rentalcar.h"
#include "database.h"
#include "login.h"
#include "signup.h"
#include "ui_carreservation.h"
#include "reservation.h"
#include "ui_reservation.h"
#include "reserv_.h"
#include "ui_reserv_.h"
#include "rentalcar_.h"
#include "ui_rentalcar_.h"
#include "reservation.h"

rentalcar::rentalcar(QString re, Database db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rentalcar),
    db(db),
    re(re)
{
    //this->db = db;
    ui->setupUi(this);
    this->on_rentalButton1_clicked();
}

rentalcar::~rentalcar()
{
    delete ui;
}

void rentalcar::on_rentalButton1_clicked() // 렌트카 조회
{
    int column, i, line=0;
    QString temp;
    ui->rentalinquiry->clearContents();
    std::cout<<re.toStdString()<<std::endl;
    sprintf(query, "SELECT * FROM Car ORDER BY Car_model");
    sql_query.exec(QString::fromLocal8Bit(query)); // QString 변경
    ui->rentalinquiry->setRowCount(sql_query.size());
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
                   ui->rentalinquiry->setItem(line, i, new QTableWidgetItem(sql_query.value(i).toString()));
               }
               line++;
           }
           ui->rentalinquiry->show();

       }
    ui->rentalinquiry->show();
}

void rentalcar::on_rentalButton2_clicked()
{
    reserv_ window(db);
    window.setModal(true);
    window.exec();
    this->on_rentalButton1_clicked();
}

void rentalcar::on_rentalRemoval_clicked() // 렌트카 삭제
{
    int row;
    if(check==true)
        row = ui->rentalinquiry->currentRow();
    else
        return;

    QString model = ui->rentalinquiry->takeItem(row, 0)->text();
    int price = ui->rentalinquiry->takeItem(row, 1)->text().toInt()/10;
    QMessageBox::information(this, "위약금", "취소 위약금 "+ QString::number(price) +"원입니다.");

    sprintf(query, "DELETE FROM Car WHERE Car_model ='%s'", model.toLocal8Bit().data());
    sql_query.exec(QString::fromLocal8Bit(query));
    if(sql_query.lastError().type() == QSqlError::NoError)
    {
        ui->rentalinquiry->removeRow(row);
    }
    else
    {
        QMessageBox::information(this, "error", "삭제 실패");
    }
    check = false;
}

void rentalcar::on_rentalChange_clicked()// 렌트카 추가
{
    int row;
    if(check==true)
        row = ui->rentalinquiry->currentRow();
    else
        return;

    QString model = ui->rentalinquiry->takeItem(row, 0)->text();
    check = false;
    rentalcar_ window(model, db);
    window.setModal(true);
    window.exec();
    this->on_rentalButton1_clicked();
}

void rentalcar::on_payment_But2_clicked()
{
    int row;
    if(check==true)
        row = ui->rentalinquiry->currentRow();
    else
        return;

    QString model = ui->rentalinquiry->takeItem(row, 0)->text();
    int price = ui->rentalinquiry->takeItem(row, 1)->text().toInt();
    QMessageBox::information(this, "결제", "결제액 "+ QString::number(price) +"원입니다.");

    sprintf(query, "DELETE FROM Car WHERE Car_model ='%s'", model.toLocal8Bit().data());
    sql_query.exec(QString::fromLocal8Bit(query));
    if(sql_query.lastError().type() == QSqlError::NoError)
    {
        ui->rentalinquiry->removeRow(row);
    }
    else
    {
        QMessageBox::information(this, "error", "삭제 실패");
    }
    check = false;
}

void rentalcar::on_exit_clicked()
{
    this->close();
}


void rentalcar::on_rentalinquiry_itemClicked()
{
    check=true;
}
