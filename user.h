#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QDialog>
#include <iostream>
#include <string>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class user; }
QT_END_NAMESPACE

class user : public QDialog
{
    Q_OBJECT

public:
    explicit user(Database db, QWidget *parent = nullptr);
    ~user();

private slots:

    void on_exit_btn_clicked();

    void on_inquiry1_clicked();

private:
    Ui::user *ui;
    Database db;
    QSqlQuery sql_query;
    char query[1024];
};

#endif // USER_H
