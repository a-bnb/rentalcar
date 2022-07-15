#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QMessageBox>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include "tcp.h"
#include "database.h"
#include "thread.h"
#include <QListWidget>

namespace Ui {
class chat;
}

class chat : public QDialog
{
    Q_OBJECT

public:
    explicit chat(QString name, tcp sock, Database db, QWidget *parent = nullptr);
    ~chat();
    void closeEvent(QCloseEvent *);


private slots:
    void on_chat_btn_clicked();

    void on_chat_edit_returnPressed();

    void push_msg(QString msg);

    void on_exit_btn_clicked();

private:
    Ui::chat *ui;
    Database db;
    tcp sock;
    Thread * thd;
    QString name;
    bool check;
    QSqlQuery sql_query;
    QString query;
    char msg[1024];

};

#endif // CHAT_H
