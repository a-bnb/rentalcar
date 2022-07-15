#ifndef MEMBER_H
#define MEMBER_H

#include <QWidget>
#include <QDialog>
#include <QTableWidget>
#include <QTextEdit>
#include <iostream>
#include <string>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class member; }
QT_END_NAMESPACE

class member : public QDialog
{
    Q_OBJECT

public:
    explicit member(QString id, Database db, QWidget *parent = nullptr);
    ~member();

private slots:
    void on_userinquiry_clicked();

   // void on_userrectified_clicked();

    //void on_userescape_clicked();

    void on_userrectified_clicked();

    void on_userescape_clicked();

    void on_user_table_itemClicked(QTableWidgetItem *item);

private:
    Ui::member *ui;
    Database db;
    //QString co;
    QString id;
    QSqlQuery sql_query;
    char query[1024];
    int selected;
};

#endif // MEMBER_H
