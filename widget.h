#ifndef WIDGET_H
#define WIDGET_H

#include "bubble_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"
#include "sorting_algo.h"
#include <QComboBox>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

class Widget : public QWidget {
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
  QGraphicsScene *scene;

  // speed up and slow down buttons
  QPushButton *speed_up;
  QPushButton *speed_down;
  int speed_change_amt = 1;
  QLabel *speed;

  // number to sort
  QLineEdit *numbers;

  QPushButton *submit;
  QPushButton *random;
  // number of value to randomize
  QSpinBox *rand_num;

  // time to delay between sorting actions
  const double base_delay_time = 250;
  double delay_time = base_delay_time;

  // graphics
  QBrush brush;
  QList<QPen> pens;
  void init_pens();

  std::vector<int> nums;

  // bars for the sorting demo
  QList<QGraphicsRectItem *> bars;

  sorting_algo *sorter;

  // sorting algo enum
  enum Sort {
    INSERTION,
    SELECTION,
    BUBBLE,
    QUICK,
    MERGE,
    HEAP,
  };

  // sort selection combo box
  QComboBox *combo_box;

  // create base for each sorting algorithm
  sorting_algo *insertion = new insertion_sort(delay_time);
  sorting_algo *selection = new selection_sort(delay_time);
  sorting_algo *bubblesort = new bubble_sort(delay_time);
  sorting_algo *quicksort = new quick_sort(delay_time);
  sorting_algo *mergesort = new merge_sort(delay_time);
  sorting_algo *heapsort = new heap_sort(delay_time);

  void switch_sort(Sort s);

  void stop();

  void fit();

  double delayed = 0;

private slots:
  void randomize();
  void sort();
  void update(std::vector<int> n);
  void sorted();
  void edit();
  void select_sort();

  // speed slots
  void change_speed(int amt);
};
#endif // WIDGET_H
