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
#include <QComboBox>
#include <vector>
#include "sorting_algo.h"
#include "insertion_sort.h"
#include "selection_sort.h"

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
    void add_nums_to_line_edit();

    QGraphicsView *view;
    QGraphicsScene* scene;

    //number to sort
    QLineEdit* numbers;

    QPushButton* submit;
    QPushButton* random;
    //number of value to randomize
    QSpinBox* rand_num;

    //time to delay between sorting actions
    int delay_time = 250;

    //graphics
    QBrush brush;
    QList<QPen> pens;
    void init_pens();

    std::vector<int> nums;


    //bars for the sorting demo
    QList<QGraphicsRectItem*> bars;

    sorting_algo* sorter;

    //sorting algo enum
    enum Sort{
        INSERTION,
        SELECTION
    };

    //sort selection combo box
    QComboBox* combo_box;

    //create base for each sorting algorithm
    sorting_algo* insertion = new insertion_sort(delay_time);
    sorting_algo* selection = new selection_sort(delay_time);

    void switch_sort(Sort s);

private slots:
    void randomize();
    void sort();
    void update(int n, int w = -1);
    void sorted();
    void edit();
    void select_sort();
};
#endif // WIDGET_H
