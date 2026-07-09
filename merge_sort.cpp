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

  // split array into two sub arrays
  std::vector<int> l;
  std::vector<int> h;

  // get mid point
  int mid = arr.size() / 2;
  update({&arr[mid]});

  // copy element over to lower array
  for (int i = 0; i < mid; i++) {
    l.push_back(arr[i]);
  }

  // copy elements over to upper part of the array
  for (int i = mid; i < arr.size(); i++) {
    h.push_back(arr[i]);
  }

  // remove an replace
  remove(arr, {&l, &h});
  update({&l.back(), &h.front()});

  // merge sort both arrays
  mergesort(l);
  _IS_ALIVE_
  mergesort(h);
  _IS_ALIVE_

  // add arr to arrays
  auto it = std::find(arrays.begin(), arrays.end(), &l);
  arrays.insert(it, &arr);

  // combin arrays into sorted array
  merge(arr, l, h);

  remove(l);
  remove(h);

  // arrays.push_back(&arr);
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
      update({&b[0]});
      arr.push_back(b.front());

      b.erase(b.begin());
    } else if (b.empty()) {
      update({&a[0]});
      arr.push_back(a.front());
      a.erase(a.begin());
    } else if (a.front() < b.front()) {
      update({&a[0], &b[0]});
      arr.push_back(a.front());
      a.erase(a.begin());
    } else {
      update({&a[0], &b[0]});
      arr.push_back(b.front());
      b.erase(b.begin());
    }

    update({&arr.back()});
  }
}

void merge_sort::remove(std::vector<int> &arr,
                        std::vector<std::vector<int> *> r) {
  auto it = std::find(arrays.begin(), arrays.end(), &arr);

  if (it != arrays.end()) {
    // replace with arrays from r
    for (std::vector<int> *a : r) {
      it = arrays.insert(it, a);
      it = std::next(it);
    }

    // arr is in list of arrays
    arrays.erase(it); // remove from list of arrays
  }
}

void merge_sort::update(std::vector<int *> nums) {
  array->clear();
  int i = 0;
  std::vector<int> indices = {};
  for (auto a : arrays) {
    for (int j = 0; j < a->size(); j++) {
      array->push_back(a->at(j));
      // check if n is in nums
      auto it = std::find(nums.begin(), nums.end(), &a->at(j));
      if (it != nums.end()) {
        // n is in nums, add to indices
        indices.push_back(i);
        // remove n from nums
        nums.erase(it);
      }
      i++;
    }
    array->push_back(-1);
  }

  emit updated(indices);
}
