#include "reserv_.h"
#include "ui_reserv_.h"

reserv_::reserv_(Database db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reserv_),
    db(db)
{
    ui->setupUi(this);
    this->on_again_btn_clicked();
    this->se="";
}

reserv_::reserv_(QString se, Database db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reserv_),
    db(db),
    se(se)

{
    ui->setupUi(this);
    this->on_again_btn_clicked();
    this->edit_set();
}

reserv_::~reserv_()
{
    delete ui;
}


void reserv_::edit_set()
{
    ui->member_text->setText(se);
    sprintf(query, "SELECT * FROM reserv WHERE reserv_id=%s", se.toLocal8Bit().data());
    sql_query.exec(QString::fromLocal8Bit(query));
    if(sql_query.size() != 0)
    {
        sql_query.next();
        ui->model_text->setText(sql_query.value(1).toString());
        ui->rent_text->setText(sql_query.value(2).toString());
        ui->return_text->setText(sql_query.value(3).toString());
        ui->price_text->setText(sql_query.value(4).toString());
    }
    else
    {
        this->close();
    }
}

void reserv_::on_again_btn_clicked()
{
    int line=0;
    ui->member_text->clear();
    ui->model_text->clear();
    ui->rent_text->clear();
    ui->return_text->clear();
    ui->price_text->clear();
    ui->user_table1->clearContents();
    ui->car_table->clearContents();

    sprintf(query, "SELECT userid FROM user");
    sql_query.exec(QString::fromLocal8Bit(query));
    ui->user_table1->setRowCount(sql_query.size());
    if(sql_query.size() != 0)
    {
        while(sql_query.next())
        {
            ui->user_table1->setItem(line++, 0, new QTableWidgetItem(sql_query.value(0).toString()));
        }
        line=0;
    }
    else
        return;
    ui->user_table1->show();

    sprintf(query, "SELECT Car_model FROM Car WHERE Car_stock>0");
    sql_query.exec(QString::fromLocal8Bit(query));
    ui->car_table->setRowCount(sql_query.size());
    if(sql_query.size() != 0)
    {
        while(sql_query.next())
        {
            ui->car_table->setItem(line++, 0, new QTableWidgetItem(sql_query.value(0).toString()));
        }
        line=0;
    }
    else
        return;
    ui->car_table->show();

}


void reserv_::on_new_btn_clicked()
{
    QList<QString> reserv_list;
    reserv_list.append(ui->member_text->text());
    reserv_list.append(ui->model_text->text());
    reserv_list.append(ui->rent_text->text());
    reserv_list.append(ui->return_text->text());
    reserv_list.append(ui->price_text->text());
    sql_query.first();

    if(se=="")
    {
        sprintf(query, "INSERT INTO reserv(client_id, Car_model, rental_date, return_date, reserv_price) VALUES('%s', '%s', '%s', '%s', '%s')",
                reserv_list.value(0).toLocal8Bit().data(),reserv_list.value(1).toLocal8Bit().data(),
                reserv_list.value(2).toLocal8Bit().data(),reserv_list.value(3).toLocal8Bit().data(),
                reserv_list.value(4).toLocal8Bit().data());
    }
    else
    {
        sprintf(query, "UPDATE reserv SET  client_id='%s', Car_model='%s', rental_date='%s', return_date='%s', reserv_price='%s' WHERE client_id='%s'",
                reserv_list.value(0).toLocal8Bit().data(),reserv_list.value(1).toLocal8Bit().data(),
                reserv_list.value(2).toLocal8Bit().data(),reserv_list.value(3).toLocal8Bit().data(),
                reserv_list.value(4).toLocal8Bit().data(),se.toLocal8Bit().data());
    }
    sql_query.exec(QString::fromLocal8Bit(query));
    if(sql_query.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::information(this, "error", "데이터베이스 접근 오류");
        std::cout<<sql_query.lastError().text().toStdString()<<std::endl;
    }
    else
    {
        QMessageBox::information(this,"message", ui->new_btn->text()+" 완료");
        this->close();
    }
}

void reserv_::on_diaryWidget_clicked(const QDate &date)
{
    if(ui->model_text->text()=="")
        return;
    if(ui->price_text->text()!="")
        return;
    int diff;
    if(ui->rent_text->text()=="")
        ui->rent_text->setText(date.toString());
    else if(ui->return_text->text()=="")
    {
        diff = date.daysTo(QDate::fromString(ui->rent_text->text()));
        std::cout<<diff<<std::endl;
        diff = diff*price_base*-1;
        std::cout<<diff<<std::endl;
        ui->price_text->setText(QString::number(diff));
        ui->return_text->setText(date.toString());
    }
}
/*void reserv_::on_diaryWidget_activated(const QDate &date)
{
    if(ui->model_text->text()=="")
        return;
    if(ui->price_text->text()!="")
        return;
    int diff;
    if(ui->rent_text->text()=="")
        ui->rent_text->setText(date.toString());
    else if(ui->return_text->text()=="")
    {
        diff = date.daysTo(QDate::fromString(ui->rent_text->text()));
        std::cout<<diff<<std::endl;
        diff = diff*price_base*-1;
        std::cout<<diff<<std::endl;
        ui->price_text->setText(QString::number(diff));
        ui->return_text->setText(date.toString());
    }
}*/

void reserv_::on_car_table_itemClicked(QTableWidgetItem *item)
{

    /*if(ui->model_text->text()=="")
        return;
    if(ui->price_text->text()!="")
        return;
    sprintf(query, "SELECT Car_price FROM Car WHERE Car_model='%s'", item->text().toLocal8Bit().data());
    sql_query.exec(QString::fromLocal8Bit(query));
    if(sql_query.size() != 0)
    {
        sql_query.next();
        std::cout<<sql_query.value(0).toString().toStdString()<<std::endl;
        price_base=sql_query.value(0).toInt();
        std::cout<<price_base<<std::endl;
        ui->model_text->setText(item->text());
    }
    else
        return;*/
    ui->model_text->setText(item->text());
}
/*void reserv_::on_car_table_cellActivated(QTableWidgetItem *item)
{
    if(ui->model_text->text()=="")
        return;
    if(ui->price_text->text()!="")
        return;
    sprintf(query, "SELECT Car_price FROM Car WHERE Car_model='%s'", item->text().toLocal8Bit().data());
    sql_query.exec(QString::fromLocal8Bit(query));
    if(sql_query.size() != 0)
    {
        sql_query.next();
        std::cout<<sql_query.value(0).toString().toStdString()<<std::endl;
        price_base=sql_query.value(0).toInt();
        std::cout<<price_base<<std::endl;
        ui->model_text->setText(item->text());
    }
    else
        return;
}*/

void reserv_::on_user_table1_itemClicked(QTableWidgetItem *item)
{
    ui->member_text->setText(item->text());
}

/*void reserv_::on_user_table1_cellActivated(QTableWidgetItem *item)
{
    ui->model_text->setText(item->text());
}*/

void reserv_::on_exit_3_clicked()
{
    this->close();
}
