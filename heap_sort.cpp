#include "heap_sort.h"

heap_sort::heap_sort(int d) : sorting_algo(d) {}

void heap_sort::sort(std::vector<int> &arr) {
  // heapify the array
  heapify(arr, 0);
  emit updated({});

  emit sorted();
}

void heap_sort::heapify(std::vector<int> &arr, int i) {

  if (i >= arr.size())
    return;

  // check if i is larger then its children
  int c1 = ((i + 1) * 2) - 1;
  int c2 = c1 + 1;

  // if i has no children return
  if (c1 >= arr.size())
    return;

  int max = c1;
  // find the largest child
  if (c2 < arr.size() && arr[c2] > arr[c1])
    max = c2;

  // swap with child if child is large
  if (arr[max] > arr[i])
    swap(arr, i, max);

  // heapify on children
  heapify(arr, c1);
  heapify(arr, c2);
}
