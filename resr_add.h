#ifndef RESR_ADD_H
#define RESR_ADD_H

#include <QDialog>

namespace Ui {
class resr_add;
}

class resr_add : public QDialog
{
    Q_OBJECT

public:
    explicit resr_add(QWidget *parent = nullptr);
    ~resr_add();

private:
    Ui::resr_add *ui;
};

#endif // RESR_ADD_H
