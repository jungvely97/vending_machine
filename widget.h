#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int money_{0};
    void button();

private slots:
    void on_pb500_clicked();
    void on_pb100_clicked();
    void on_pb50_clicked();
    void on_pb10_clicked();
    void on_coffee_clicked();
    void on_tea_clicked();
    void on_cola_cliced();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

