#ifndef CONTDATA_H
#define CONTDATA_H

#include <QWidget>
#include <QDialog>
#include <iostream>
#include <string>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class contdata; }
QT_END_NAMESPACE

class contdata : public QDialog
{
    Q_OBJECT

public:
    explicit contdata(Database db, QWidget *parent = nullptr);
    ~contdata();

private slots:

    void on_contdataButton1_clicked();

    void on_contdataButton2_clicked();

private:
    Ui::contdata *ui;
    Database db;
    QSqlQuery sql_query;
    char query[1024];
};

#endif // CONTDATA_H
