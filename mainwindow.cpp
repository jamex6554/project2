#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include <iostream>
#include <ctime>
#include <QKeyEvent>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    change();
    restart();

    ui->label_2->hide();
    ui->label_3->hide();
    start();
    assign();
    score=0;
    win_time=0;

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            painter.drawPixmap(j*100+30,i*100+30,100,100,*output_box[i][j]);
        }
    }
}
void MainWindow::change()
{
    zero[0].load(":/zero.jpg");
    zero[1].load(":/image/one.jpg");
    zero[2].load(":/image/two.jpg");
    zero[3].load(":/three.jpg");
    zero[4].load(":/four.jpg");
    zero[5].load(":/five.jpg");
    zero[6].load(":/six.jpg");
    zero[7].load(":/seven.jpg");
    zero[8].load(":/eight.jpg");
    zero[9].load(":/nine.jpg");
    zero[10].load(":/ten.jpg");
    zero[11].load(":/eleven.jpg");

}

void MainWindow::move_left_new(){
    int i,j,k,total,ex_total;
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            for (k=0; k<3; k++) {
                if(0==box[i][k]){
                    box[i][k]=box[i][k+1];
                    box[i][k+1]=0;
                }

            }
        }
    }
    for (i=0; i<4; i++) {
        for (j=0; j<3; j++) {
            if (box[i][j]==box[i][j+1]&&box[i][j]!=0) {
                box[i][j]++;
                box[i][j+1]=0;
                total=1;
                for(k=0;k<box[i][j];k++){
                    ex_total=2;
                    total=total*ex_total;
                }
                score=score+total;
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            for (k=0; k<3; k++) {
                if(0==box[i][k]){
                    box[i][k]=box[i][k+1];
                    box[i][k+1]=0;
                }

            }
        }
    }
}

void MainWindow::move_right_new(){
    int i,j,k,total,ex_total;
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            for (k=0; k<3; k++) {
                if(0==box[i][3-k]){
                    box[i][3-k]=box[i][3-(k+1)];
                    box[i][3-(k+1)]=0;
                }
            }
        }
    }
    for (i=0; i<4; i++) {
        for (j=0; j<3; j++) {
            if (box[i][3-j]==box[i][3-(j+1)]&&box[i][3-j]!=0) {
                box[i][3-j]++;
                box[i][3-(j+1)]=0;
                total=1;
                for(k=0;k<box[i][3-j];k++){
                ex_total=2;
                total=total*ex_total;
                }
                score=score+total;
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            for (k=0; k<3; k++) {
                if(0==box[i][3-k]){
                    box[i][3-k]=box[i][3-(k+1)];
                    box[i][3-(k+1)]=0;
                }
            }
        }
    }
}

void MainWindow::move_up_new(){
    int i,j,k,total,ex_total;
    for(k=0;k<4;k++){
        for(j=0;j<3;j++){
            for (i=0; i<3; i++) {
                if(0==box[i][k]){
                    box[i][k]=box[i+1][k];
                    box[i+1][k]=0;
                }

            }
        }
    }
    for (j=0; j<4; j++) {
        for (i=0; i<3; i++) {
            if (box[i][j]==box[i+1][j]&&box[i][j]!=0) {
                box[i][j]++;
                box[i+1][j]=0;
                total=1;
                for(k=0;k<box[i][j];k++){
                ex_total=2;
                total=total*ex_total;
                }
                score=score+total;
            }
        }
    }
    for(k=0;k<4;k++){
        for(j=0;j<3;j++){
            for (i=0; i<3; i++) {
                if(0==box[i][k]){
                    box[i][k]=box[i+1][k];
                    box[i+1][k]=0;
                }

            }
        }
    }
}

void MainWindow::move_down_new(){
    int i,j,k,total,ex_total;
    for(k=0;k<4;k++){
        for(j=0;j<3;j++){
            for (i=0; i<3; i++) {
                if(0==box[3-i][k]){
                    box[3-i][k]=box[3-(i+1)][k];
                    box[3-(i+1)][k]=0;
                }

            }
        }
    }
    for (j=0; j<4; j++) {
        for (i=0; i<3; i++) {
            if (box[3-i][j]==box[3-(i+1)][j]&&box[3-i][j]!=0) {
                box[3-i][j]++;
                box[3-(i+1)][j]=0;
                total=1;
                for(k=0;k<box[3-i][j];k++){
                ex_total=2;
                total=total*ex_total;
                }
                score=score+total;
            }
        }
    }
    for(k=0;k<4;k++){
        for(j=0;j<3;j++){
            for (i=0; i<3; i++) {
                if(0==box[3-i][k]){
                    box[3-i][k]=box[3-(i+1)][k];
                    box[3-(i+1)][k]=0;
                }

            }
        }
    }
}

void MainWindow::ramdom(){
    srand(time(NULL));
    int i,j,counter=0,ano_counter,lose_counter1,lose_counter2,lose_counter3;
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            if (0==box[i][j]) {
                counter++;
                break;
            }
            else if (11==box[i][j]){
                ui->label_3->show();
                win_time++;
                return;
            }
        }
    }
    if (0==counter) {
        lose_counter1=0;
        lose_counter2=0;
        lose_counter3=0;
        for (i=0; i<3; i++) {
            if (box[i][3]!=box[i+1][3]) {
                lose_counter1++;
            }
        }
        for (j=0; j<3; j++) {
            if (box[3][j]!=box[3][j+1]) {
                lose_counter2++;
            }
        }
        for (i=0; i<3; i++) {
            for (j=0; j<3; j++) {
                if (box[i][j]!=box[i+1][j]&&box[i][j]!=box[i][j+1]) {
                    lose_counter3++;
                }
            }
        }
        if (15==lose_counter1+lose_counter2+lose_counter3) {
            ui->label_2->show();
            return;
        }
    }
    else{
        ano_counter=0;
        while (0==ano_counter) {
            i=rand()%4;
            j=rand()%4;
            if (0==box[i][j]){
                box[i][j]=1;
                ano_counter++;
            }
        }
    }
    /*for (i=0; i<4; i++) {
        printf("\n");
        for (j=0; j<4; j++) {
            printf("%d",box[i][j]);
        }
    }*/
}


void MainWindow::start(){
    srand(time(NULL));
    int i,j,ano_counter=0;
    while (ano_counter<2) {
        i=rand()%4;
        j=rand()%4;
        if (0==box[i][j]){
            box[i][j]=1;
            ano_counter++;
        }
    }
    /*for (i=0; i<4; i++) {
        printf("\n");
        for (j=0; j<4; j++) {
            printf("%d",box[i][j]);
        }
    }*/
    assign();
    update();
}
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(0==win_time){
        switch (e->key())
            {
                case Qt::Key_Up : move_up_new();ramdom();assign();the_score();update(); break;
                case Qt::Key_Down : move_down_new();ramdom();assign();the_score();update(); break;
                case Qt::Key_Left : move_left_new();ramdom();assign();the_score();update(); break;
                case Qt::Key_Right : move_right_new();ramdom();assign();the_score();update(); break;
                case Qt::Key_R : restart();start();break;
                case Qt::Key_B : trace_back();assign();break;
            }
    }
   else{
           return;
   }
}
void MainWindow::the_score(){
    QString str=QString::number(score);
    ui->label->setText("score:"+str);
}

void MainWindow::restart(){
    int i,j;
    score=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            box[i][j]=0;
        }
    }
}

void MainWindow::assign(){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            output_box[i][j]=&zero[box[i][j]];
        }
    }
}
void MainWindow::trace_back(){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;i++){
            before_box[i][j]=box[i][j];
        }
    }
}
