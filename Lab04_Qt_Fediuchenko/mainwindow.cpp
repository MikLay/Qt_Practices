#include "mainwindow.h"
#include "person.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    modelLeft = new QStringListModel(this);
    modelRight = new QStringListModel(this);

    QStringList leftList;
    QStringList rightList;
    for(int i = 0; i < 40; i++){
        if(rand() % 2 == 0)
            leftList.append(Person::generatePerson().getName().c_str());
        else {
            rightList.append(Person::generatePerson().getName().c_str());
        }
    }
    modelLeft->setStringList(leftList);
    modelRight->setStringList(rightList);

    ui->leftListView->setModel(modelLeft);
    ui->leftListView->setDragDropMode(QAbstractItemView::DragDrop);
    ui->leftListView->setDefaultDropAction(Qt::MoveAction);

    ui->rightListView->setModel(modelRight);
    ui->rightListView->setDragDropMode(QAbstractItemView::DragDrop);
    ui->rightListView->setDefaultDropAction(Qt::MoveAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}
