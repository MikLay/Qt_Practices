#ifndef MODELVIEW_H
#define MODELVIEW_HL

#include <QStringListModel>
#include <QAbstractItemView>
#include "QStandardItemModel"
#include "QStandardItem"
#include <QSortFilterProxyModel>
#include <QDialog>
#include <QStringList>

namespace Ui {
class ModelView;
}

class ModelView : public QDialog
{
    Q_OBJECT

public:
    explicit ModelView(QWidget *parent = nullptr);
    ~ModelView();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_nameSearch_textEdited(const QString &arg1);
    void on_numberSearch_textEdited(const QString &arg1);

private:
    Ui::ModelView *ui;
    QStandardItemModel *model;
    QSortFilterProxyModel *proxyModel;
    QSortFilterProxyModel *proxyModel2;
};

#endif // MODELVIEW_H
