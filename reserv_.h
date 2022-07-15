#ifndef RESERV__H
#define RESERV__H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QTableWidget>
#include <QDebug>
#include "database.h"
#include <iostream>
#include <string>

namespace Ui {
class reserv_;
}

class reserv_ : public QDialog
{
    Q_OBJECT

public:
    explicit reserv_(Database db, QWidget *parent = nullptr);
    explicit reserv_(QString se, Database db, QWidget *parent = nullptr);
    ~reserv_();
    void edit_set();

private slots:
    //void on_exit__clicked();

    //void on_add_btn_2_clicked();

    void on_again_btn_clicked();

    //void on_add_btn_clicked();

    void on_new_btn_clicked();

    //void on_diaryWidget_activated(const QDate &date);

    //void on_car_table_cellActivated(QTableWidgetItem *item);

    void on_exit_3_clicked();

    //void on_user_table1_cellActivated(QTableWidgetItem *item);

    void on_diaryWidget_clicked(const QDate &date);

    //void on_car_table_cellClicked(int row, int column);

    void on_car_table_itemClicked(QTableWidgetItem *item);

    void on_user_table1_itemClicked(QTableWidgetItem *item);

    //void on_car_table_cellActivated(int row, int column);

private:
    Ui::reserv_ *ui;
    Database db;
    QString se;
    QSqlQuery sql_query;
    char query[1024];
    bool check;
    int price_base;
};

#endif // RESERV__H
