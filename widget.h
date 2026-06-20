#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QList>
#include <QSpinBox>
#include <vector>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    void create_bars();
    void update_bars();
    void clear();

    QGraphicsView *view;
    QGraphicsScene* scene;

    //number to sort
    QLineEdit* numbers;

    QPushButton* submit;
    QPushButton* random;
    //number of value to randomize
    QSpinBox* rand_num;

    QBrush brush;
    QPen pen;

    std::vector<int> nums;


    //bars for the sorting demo
    QList<QGraphicsRectItem*> bars;

private slots:
    void randomize();

    void sort();
};
#endif // WIDGET_H
