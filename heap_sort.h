#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "sorting_algo.h"
#include <QObject>

class heap_sort : public sorting_algo {
  Q_OBJECT
public:
  heap_sort(int d);
  void sort(std::vector<int> &arr) override;

private:
  int last;
  void heapify(std::vector<int> &arr, int i);
  void build_max_heap(std::vector<int> &arr);
};

#endif // HEAP_SORT_H
