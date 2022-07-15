#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QDialog>
#include "content.h"
#include "database.h"
#include "tcp.h"

namespace Ui {
class mainpage;
}

class mainpage : public QDialog
{
    Q_OBJECT

public:
    explicit mainpage(tcp sock, QString ty, QString re, QString co, QString id, QWidget *parent = nullptr);
    ~mainpage();

private slots:
    //void on_beachPush_clicked();

    void on_userPush_clicked();

    void on_contentPush_clicked();

    void on_rentalPush_clicked();

    //void on_Reserv_Push_clicked();

    void on_chat_btn_clicked();

private:
    Ui::mainpage *ui;
    Database db;
    QString co;
    QString id;
    QString re;
    QString ty;
    QSqlQuery sql_query;
    tcp sock;
    char query[1024];
};

#endif // MAINPAGE_H
