#include "resr_add.h"
#include "ui_resr_add.h"

resr_add::resr_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resr_add)
{
    ui->setupUi(this);
}

resr_add::~resr_add()
{
    delete ui;
}
