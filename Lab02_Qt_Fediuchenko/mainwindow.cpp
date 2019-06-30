#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QString height = "Height: ";
    height+=QString::number(this->geometry().size().height());
    QString width = "Width: ";
    width+=QString::number(this->geometry().size().width());
    ui->label_height->setText(height);
    ui->label_width->setText(width);
    QWidget::resizeEvent(event);
}
