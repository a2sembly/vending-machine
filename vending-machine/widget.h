#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int Current_Money = 0;
    void moneyChange(int input);

private slots:
    void on_Reset_clicked();

    void on_pb_10_clicked();

    void on_pb_50_clicked();

    void on_pb_100_clicked();

    void on_pb_500_clicked();

    void on_Coffee_clicked();

    void on_Milk_clicked();

    void on_Tea_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
