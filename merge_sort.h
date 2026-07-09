#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "sorting_algo.h"
#include <QObject>

class merge_sort : public sorting_algo {
  Q_OBJECT
public:
  merge_sort(int d);
  void sort(std::vector<int> &arr) override;

private:
  // vector holding arrays used for merge sort
  std::vector<std::vector<int> *> arrays;
  std::vector<int> *array; // original arr
  void mergesort(std::vector<int> &arr);
  void merge(std::vector<int> &arr, std::vector<int> &a, std::vector<int> &b);
  void remove(std::vector<int> &arr, std::vector<std::vector<int> *> r = {});
  void update(std::vector<int> nums = {});
};

#endif // MERGE_SORT_H
