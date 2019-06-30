#include<bits/stdc++.h>
#include <QString>
#include <QList>
#include <QInputDialog>
#include <QDebug>

#include "modelview.h"
#include "ui_dialog.h"
#include "contact.h"

ModelView::ModelView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelView),
    proxyModel(new QSortFilterProxyModel()),
    proxyModel2(new QSortFilterProxyModel()),
    model(new QStandardItemModel(this))
{
    ui->setupUi(this);

    QStandardItem *item;

    QStringList horizontalHeader;
    horizontalHeader.append("Ім'я");
    horizontalHeader.append("Номери");
    model->setHorizontalHeaderLabels(horizontalHeader);

    QFile file("C:\\Users\\mixei\\source\\repos\\QTRepos\\Lab01_Qt_Fediuchenko\\BaseContacts.txt");
    file.open(QIODevice::ReadOnly);
    QString textString = file.readAll();
    QStringList text = textString.split(";");
    int i = 0;
    for(QString contact:text)
    {
        QStringList objectContact = contact.split(":");
        if(objectContact.first() == "")
            continue;
        model->setItem(i, 0 , new QStandardItem(objectContact.first()));
        model->setItem(i++, 1 , new QStandardItem(objectContact.last()));
    }
    file.close();


    ui->tableView->setModel(proxyModel);
    proxyModel->setSourceModel(proxyModel2);
    proxyModel2->setSourceModel(model);
    ui->tableView->
            setEditTriggers(QAbstractItemView::AnyKeyPressed |
                            QAbstractItemView::DoubleClicked);
    ui->tableView->resizeRowsToContents();
}

ModelView::~ModelView()
{
    delete ui;
}




//Buttons & Fields

void ModelView::on_pushButton_clicked()
{
    QList<QStandardItem*>itemList;
    bool ok = true;
    QList<QString> phones;
    QString name = QInputDialog().getText(nullptr, "name", "name", QLineEdit::Normal, "", &ok);
    if(!ok) return;
    QString phone;

    while(true){
        QInputDialog inputDialog;
        inputDialog.setInputMode(QInputDialog::TextInput);
        inputDialog.setCancelButtonText("Stop adding");
        inputDialog.setOkButtonText("Add number");
        inputDialog.setLabelText("Phone numbers");
        inputDialog.exec();
        phone = inputDialog.textValue();
        if(phone.length() == 0) break;
        phones.push_back(phone);
    }

    Contact p = Contact(name, phones);
    itemList.append(new QStandardItem(p.name()));
    itemList.append(new QStandardItem(p.getNumbersQString()));

    int row = model->rowCount();
    model->appendRow(itemList);
    QModelIndex index = model->index(row, 0);
    ui->tableView->setCurrentIndex(index);
    ui->tableView->edit(index);
    ui->tableView->resizeRowsToContents();
}

void ModelView::on_pushButton_2_clicked()
{
    model->removeRows(ui->tableView->currentIndex().row(),1);
    ui->tableView->resizeRowsToContents();
}

void ModelView::on_nameSearch_textEdited(const QString &arg1)
{
    proxyModel->setFilterRegExp(arg1);
    proxyModel->setFilterKeyColumn(0);
}

void ModelView::on_numberSearch_textEdited(const QString &arg1)
{
    proxyModel2->setFilterRegExp(arg1);
    proxyModel2->setFilterKeyColumn(1);
}
