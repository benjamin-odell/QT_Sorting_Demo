#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "sorting_algo.h"
#include <QObject>

class heap_sort : public sorting_algo {
  Q_OBJECT
public:
  heap_sort(int d);

private:
  void heapify(std::vector<int> &arr, int i);
};

#endif // HEAP_SORT_H
