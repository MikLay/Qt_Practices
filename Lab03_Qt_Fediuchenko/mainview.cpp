#include "mainview.h"
#include "ui_mainview.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

MainView::MainView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::on_processReading_clicked()
{
    QFile fileReadFrom(ui->readFile->text());
    QFile fileWriteTo(ui->writeFile->text());

    if(fileReadFrom.exists() && fileWriteTo.exists())
    {
        fileReadFrom.open(QIODevice::ReadOnly);
        fileWriteTo.open(QIODevice::Append | QIODevice::Text);
        QTextStream outStream(&fileWriteTo);
        char file_data;
        while(!fileReadFrom.atEnd())
        {
          fileReadFrom.read(&file_data,sizeof(char));
          if(file_data == '\n'){
              continue;
          }else if(file_data == '\r'||file_data=='\v'){
              outStream << " ";
          }else{
              outStream << file_data;
          }
        }
        QMessageBox::information(this, "", "Text copied");
    }else{
        QMessageBox::information(this, "", "Wrong path specified");
    }
    fileReadFrom.close();
    fileWriteTo.close();
}

void MainView::on_Choose_clicked()
{

    QString pathRead = QFileDialog::getOpenFileName(this, "Open read file", "c:\\");
    ui->readFile->setText(pathRead);
}

void MainView::on_chooseWrite_clicked()
{
    QString pathWrite = QFileDialog::getOpenFileName(this, "Open write file", "c:\\");
    ui->writeFile->setText(pathWrite);
}
