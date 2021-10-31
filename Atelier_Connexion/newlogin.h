#ifndef NEWLOGIN_H
#define NEWLOGIN_H

#include <QWidget>

namespace Ui {
class newlogin;
}

class newlogin : public QWidget
{
    Q_OBJECT

public:
    explicit newlogin(QWidget *parent = nullptr);
    ~newlogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newlogin *ui;
};

#endif // NEWLOGIN_H
