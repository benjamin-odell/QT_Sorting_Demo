#include "merge_sort.h"

merge_sort::merge_sort(int d) : sorting_algo(d) {}

void merge_sort::sort(std::vector<int> &arr) {
    arrs.clear();
  a = &arr;
  // copy of main arr
  std::vector<int> t = *a;
  arrs.push_back(&t);
  mergesort(t);
  emit sorted();
}

void merge_sort::mergesort(std::vector<int> &arr) {
  _IS_ALIVE_
  // an array with one element is always sorted
  if (arr.size() <= 1)
    return;

  // remove array from list of arrays
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
  // add both arrays to list of arrays
  arrs.push_back(&l);
  arrs.push_back(&h);

  // update visuals
  update({mid});

  // merge sort both arrays
  mergesort(l);
  _IS_ALIVE_
  mergesort(h);
  _IS_ALIVE_

  // combin arrays into sorted array
  merge(arr, l, h);
  _IS_ALIVE_

  // remove sub arrays from list of arrays
  remove(l);
  remove(h);

  // add sorted array back to the list of arrays
  arrs.push_back(&arr);

  update({});
}

void merge_sort::merge(std::vector<int> &arr, std::vector<int> &a,
                       std::vector<int> &b) {
  arr.clear();
  int ap = 0;
  int bp = 0;

  // fill in the arr
  while (ap < a.size() || bp < b.size()) {
    _IS_ALIVE_
    if (ap == a.size()) {
      // a has no elements in it
      arr.push_back(b[bp]);
      bp++;
    } else if (bp == a.size()) {
      // b has no element in it
      arr.push_back(a[ap]);
      ap++;
    } else if (a[ap] < b[bp]) {
      // a is next element
      arr.push_back(a[ap]);
      ap++;
    } else {
      // b is next element
      arr.push_back(b[bp]);
      bp++;
    }
  }
}

void merge_sort::remove(std::vector<int> &arr) {
  // remove arr from arrs
  auto it = std::find(arrs.begin(), arrs.end(), &arr);
  if (it != arrs.end()) {
    // erase element at that point
    arrs.erase(it);
  }
}

void merge_sort::update(std::vector<int> nums) {
  // clear arr
  a->clear();
  for (auto arr : arrs) {
    for (int i : *arr) {
      a->push_back(i);
    }
    a->push_back(0);
  }

  emit updated(nums);
}
