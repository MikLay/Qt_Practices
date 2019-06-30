#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QDialog>

namespace Ui {
class MainView;
}

class MainView : public QDialog
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = nullptr);
    ~MainView();

private slots:
    void on_processReading_clicked();

    void on_Choose_clicked();

    void on_chooseWrite_clicked();

private:
    Ui::MainView *ui;
};

#endif // MAINVIEW_H
