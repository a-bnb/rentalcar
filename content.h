#ifndef CONTENT_H
#define CONTENT_H

#include <QWidget>
#include <QDialog>
#include <QTableWidget>
#include <QTextEdit>
#include <iostream>
#include <string>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class content; }
QT_END_NAMESPACE

class content : public QDialog
{
    Q_OBJECT

public:
    explicit content(QString co, Database db, QWidget *parent = nullptr);
    ~content();

private slots:

    void on_contentyes_clicked();

    void on_contentno_clicked();

private:
    Ui::content *ui;
    Database db;
    QString co;
    QSqlQuery sql_query;
    char query[1024];
};

#endif // CONTENT_H
