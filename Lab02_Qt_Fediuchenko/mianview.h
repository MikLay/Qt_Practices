#ifndef MIANVIEW_H
#define MIANVIEW_H

#include <QDialog>

namespace Ui {
class MianView;
}

class MianView : public QWidget
{
    Q_OBJECT

public:
    explicit MianView(QWidget *parent = nullptr);
    ~MianView();

private:
    Ui::MianView *ui;
protected:
    void resizeEvent(QResizeEvent* event);
};

#endif // MIANVIEW_H
