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

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    QGraphicsView *view;
    QGraphicsScene* scene;

    //number to sort
    QLineEdit* numbers;

    QPushButton* submit;
    QPushButton* random;


    //bars for the sorting demo
    std::vector<QGraphicsRectItem> bars;

private slots:
    void randomize();
};
#endif // WIDGET_H
