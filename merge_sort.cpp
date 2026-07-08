#include "merge_sort.h"

merge_sort::merge_sort(int d) : sorting_algo(d) {}

void merge_sort::sort(std::vector<int> &arr) {
  arrays.clear();
  std::vector<int> a = arr;
  array = &arr;
  arrays.push_back(&a);
  mergesort(a);
  emit sorted();
}

void merge_sort::mergesort(std::vector<int> &arr) {
  _IS_ALIVE_
  // an array with one element is always sorted
  if (arr.size() <= 1)
    return;

  update();

  // remove arr from list of arrays
  remove(arr);

  // split array into two sub arrays
  std::vector<int> l;
  std::vector<int> h;

  // get mid point
  int mid = arr.size() / 2;

  // copy element over to lower array
  for (int i = 0; i < mid; i++) {
    l.push_back(arr[i]);
  }

  // copy elements over to upper part of the array
  for (int i = mid; i < arr.size(); i++) {
    h.push_back(arr[i]);
  }

  // push both arrays onto the list of arrays
  arrays.push_back(&l);
  arrays.push_back(&h);
  update();

  // merge sort both arrays
  mergesort(l);
  _IS_ALIVE_
  mergesort(h);
  _IS_ALIVE_

  // combin arrays into sorted array
  merge(arr, l, h);

  remove(l);
  remove(h);

  arrays.push_back(&arr);
  update();

  _IS_ALIVE_
}

void merge_sort::merge(std::vector<int> &arr, std::vector<int> &a,
                       std::vector<int> &b) {
  arr.clear();

  // fill in the arr
  while (!a.empty() || !b.empty()) {
    _IS_ALIVE_
    if (a.empty()) {
      arr.push_back(b.front());
      b.erase(b.begin());
    } else if (b.empty()) {
      arr.push_back(a.front());
      a.erase(a.begin());
    } else if (a.front() < b.front()) {
      arr.push_back(a.front());
      a.erase(a.begin());
    } else {
      arr.push_back(b.front());
      b.erase(b.begin());
    }
  }
}

void merge_sort::remove(std::vector<int> &arr) {
  auto it = std::find(arrays.begin(), arrays.end(), &arr);

  if (it != arrays.end()) {
    // arr is in list of arrays
    arrays.erase(it); // remove from list of arrays
  }
}

void merge_sort::update(std::vector<int> nums) {
  array->clear();
  int i = 0;
  std::vector<int> indices = {};
  for (auto a : arrays) {
    for (int n : *a) {
      array->push_back(n);
      // check if n is in nums
      auto it = std::find(nums.begin(), nums.end(), n);
      if (it != nums.end()) {
        // n is in nums, add to indices
        indices.push_back(i);
        // remove n from nums
        nums.erase(it);
      }
      i++;
    }
    array->push_back(0);
  }

  emit updated(indices);
}
