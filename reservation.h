#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QTableWidget>
#include "database.h"
#include <iostream>
#include <string>

namespace Ui {
class reservation;
}

class reservation : public QDialog
{
    Q_OBJECT

public:
    explicit reservation(QString ty, Database db, QWidget *parent = nullptr);
    ~reservation();

private slots:
    //void on_pushButton_clicked();

    //void on_pushButton_3_clicked();

    //void on_pushButton_5_clicked();

    //void on_pushButton_2_clicked();

    //void on_nullity_But_clicked();

    //void on_modify_But_clicked();

    void on_again_btn_clicked();

    void on_exit__clicked();

    void on_reserv_Table_itemClicked();

    void on_payment_But_clicked();

private:
    Ui::reservation *ui;
    Database db;
    QString ty;
    QSqlQuery sql_query;
    char query[1024];
    bool check;
};

#endif // RESERVATION_H
