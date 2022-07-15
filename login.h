#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <iostream>
#include <string>

#include "database.h"
#include "tcp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(Database db, QWidget *parent = nullptr);
    ~login();

private slots:
    void on_login_btn_clicked();

    void on_exit_btn_clicked();

    void on_signup_btn_clicked();

private:
    Ui::login *ui;
    Database db;
    QSqlQuery sql_query;
    QString co;
    QString re;
    QString ty;
    char query[1024];
};
#endif // LOGIN_H
