#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include <stdio.h>
#include <time.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void move_left();//i為行,j為列
    void move_up_new();
    void move_right_new();
    void move_down_new();
    void move_left_new();
    void ramdom();
    void start();
    void lose();
    void the_score();
    void restart();
    void assign();
    void trace_back();
private:
    Ui::MainWindow *ui;
    QPixmap *fuck;
    QPixmap zero[11];
    int box[4][4],before_box[4][4];
    QPixmap *output_box[4][4];
    int score;
    int win_time;
protected:
    void paintEvent(QPaintEvent *);
    void change();
    void keyPressEvent(QKeyEvent*);
};

#endif // MAINWINDOW_H

