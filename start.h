#ifndef START_H
#define START_H

#include <QMainWindow>
#include "mainwindow.h"
namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = 0);
    ~Start();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Start *ui;
    MainWindow m;
};

#endif // START_H
