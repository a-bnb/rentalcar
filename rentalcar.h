#ifndef RENTALCAR_H
#define RENTALCAR_H

#include <QWidget>
#include <QDialog>
#include <QTableWidget>
#include <QTextEdit>
#include <iostream>
#include <string>
#include "database.h"

namespace Ui {
class rentalcar;
}

class rentalcar : public QDialog
{
    Q_OBJECT

public:
    explicit rentalcar(QString re, Database db, QWidget *parent = nullptr);
    ~rentalcar();

private slots:
    void on_rentalButton1_clicked();

    void on_exit_clicked();

    //void on_rentalButton3_clicked();

    //void on_rentalButton14_clicked();

    //void on_rentalinquiry_cellActivated(QTableWidgetItem *item);

    //void on_rentalButton1_2_clicked();

    void on_rentalButton2_clicked();

    //void on_rentalButton2_3_clicked();

    void on_rentalChange_clicked();

    void on_rentalRemoval_clicked();

    void on_rentalinquiry_itemClicked();

    void on_payment_But2_clicked();

private:
    Ui::rentalcar *ui;
    Database db;
    QString re;
    QSqlQuery sql_query;
    char query[1024];
    int selected;
    bool check;
};

#endif // RENTALCAR_H
