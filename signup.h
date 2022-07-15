#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include <iostream>

#include "database.h"

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(Database db, QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_check_btn_clicked();

    void on_exit_btn_clicked();

    void on_signup_btn_clicked();

private:
    Ui::signup *ui;
    Database db;
    bool check;
    QSqlQuery sql_query;
    char query[1024];
};

#endif // SIGNUP_H
