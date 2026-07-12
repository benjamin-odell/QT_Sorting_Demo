#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "sorting_algo.h"
#include <QObject>

class bubble_sort : public sorting_algo {
  Q_OBJECT
public:
  bubble_sort(int d);

  void sort(std::vector<int> &arr) override;
};

#endif // BUBBLE_SORT_H
