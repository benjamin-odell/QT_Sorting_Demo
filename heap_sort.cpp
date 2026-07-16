#include "heap_sort.h"

heap_sort::heap_sort(int d) : sorting_algo(d) {}

void heap_sort::sort(std::vector<int> &arr) {
  // heapify the array
  last = arr.size();
  build_max_heap(arr);
  emit updated({});

  // swap last element with first element
  for (int i = arr.size() - 1; i >= 0; i--) {
    _IS_ALIVE_
    emit updated({i, 0});
    swap(arr, 0, i);
    _IS_ALIVE_
    emit updated({0, i});
    last--;
    heapify(arr, 0);
    _IS_ALIVE_
    emit updated({});
  }

  emit sorted();
}

void heap_sort::heapify(std::vector<int> &arr, int i) {

  if (i >= last)
    return;

  // check if i is larger then its children
  int c1 = ((i + 1) * 2) - 1;
  int c2 = c1 + 1;

  // if i has no children return
  if (c1 >= last)
    return;
  _IS_ALIVE_
  if (c1 < last && c2 < last)
    emit updated({i, c1, c2});

  int max = c1;
  // find the largest child
  if (c2 < last && arr[c2] > arr[c1])
    max = c2;

  _IS_ALIVE_
  emit updated({i, max});

  // swap with child if child is large
  if (arr[max] > arr[i])
    swap(arr, i, max);

  _IS_ALIVE_
  emit updated({max, i});

  // heapify on max
  if (max < last)
    heapify(arr, max);
}

void heap_sort::build_max_heap(std::vector<int> &arr) {
  // run heapify for each parent
  for (int i = arr.size() / 2; i >= 0; i--) {
    heapify(arr, i);
  }
}
