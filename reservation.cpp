#include "reservation.h"
#include "ui_reservation.h"
#include "database.h"
#include "signup.h"
#include "rentalcar.h"
#include "ui_rentalcar.h"
#include "reserv_.h"
#include "ui_reserv_.h"
#include "rentalcar_.h"
#include "ui_rentalcar_.h"
#include "login.h"

reservation::reservation(QString ty, Database db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservation),
    db(db),
    ty(ty)
{
    this->db = db;
    ui->setupUi(this);
}

reservation::~reservation()
{
    delete ui;
}


void reservation::reservation::on_again_btn_clicked() // 예약 조회
{
    int i, column, line=0;
    QString temp;
    ui->reserv_Table->clearContents();
    sprintf(query, "SELECT * FROM reserv WHERE client_id = '%s'", ty.toLocal8Bit().data());
    sql_query.exec(QString::fromLocal8Bit(query));
    column = sql_query.record().count();
    ui->reserv_Table->setRowCount(sql_query.size());
    ui->reserv_Table->setColumnCount(column);
    if(sql_query.size() != 0)
    {
        while(sql_query.next())
        {
            for(i=0; i<column; i++)
            {
                ui->reserv_Table->setItem(line, i, new QTableWidgetItem(sql_query.value(i).toString()));
            }
            line++;
        }
        ui->reserv_Table->show();
    }
}

/*void reservation::on_pushButton_clicked()
{
    reserv_ window(db);
    window.setModal(true);
    window.exec();
    this->on_again_btn_clicked();
}*/


/*void reservation::on_nullity_But_clicked() // 예약 취소
{
    int row;
    if(check==true)
        row = ui->reserv_Table->currentRow();
    else
        return;

    QString ty = ui->reserv_Table->takeItem(row, 1)->text();
    sprintf(query, "DELETE FROM reserv WHERE reserv_id ='%s'", ty.toLocal8Bit().data());
    sql_query.exec(QString::fromLocal8Bit(query));
    if(sql_query.lastError().type() == QSqlError::NoError)
    {
        QMessageBox::information(this, "message", "Delete Complete!");
        ui->reserv_Table->removeRow(row);
    }
    else
    {
        QMessageBox::information(this, "error", "삭제 실패");
    }
    check = false;
}*/


/*void reservation::on_modify_But_clicked()// 예약 변경
{
    int row;
    if(check==true)
        row = ui->reserv_Table->currentRow();
    else
        return;

    QString name = ui->reserv_Table->takeItem(row, 1)->text();
    check = false;
    reserv_ window(name, db);
    window.setModal(true);
    window.exec();
    this->on_again_btn_clicked();
}*/

void reservation::on_payment_But_clicked()
{


}

void reservation::on_exit__clicked()
{
    this->close();
}

void reservation::on_reserv_Table_itemClicked()
{
    check=true;
}
