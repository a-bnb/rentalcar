#ifndef RENTALCAR__H
#define RENTALCAR__H

#include <QDialog>
#include <QMessageBox>
#include <iostream>
#include <cstring>
#include "database.h"

namespace Ui {
class rentalcar_;
}

class rentalcar_ : public QDialog
{
    Q_OBJECT

public:
    explicit rentalcar_(Database db, QWidget *parent = nullptr);
    explicit rentalcar_(QString model, Database db, QWidget *parent = nullptr);
    ~rentalcar_();
    void edit_set();

private slots:
    void on_check_btn_clicked();

    void on_update_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::rentalcar_ *ui;
    Database db;
    QString model;
    bool check;
    QSqlQuery sql_query;
    char query[1024];
};

#endif // RENTALCAR__H
