#ifndef STUDENTWINDOW1_H
#define STUDENTWINDOW1_H

#include <QDialog>
// change made by sijan
namespace Ui {
class studentwindow1;
}

class studentwindow1 : public QDialog
{
    Q_OBJECT

public:
    explicit studentwindow1(QWidget *parent = nullptr);
    ~studentwindow1();

private slots:
    void okbutton();

    void backbutton();

private:
    Ui::studentwindow1 *ui;
};

#endif // STUDENTWINDOW1_H
