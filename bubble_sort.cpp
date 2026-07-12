#include "bubble_sort.h"

bubble_sort::bubble_sort(int d) : sorting_algo(d) {}

void bubble_sort::sort(std::vector<int> &arr) {
  // loop through the whole array for each element
  for (int i = 0; i < arr.size(); i++) {
    // loop through each element in the array starting at index 1
    for (int j = 1; j < arr.size() - i; j++) {
      // swap in number before j is larger
      emit updated({j});
      _IS_ALIVE_
      emit updated({j, j - 1});
      if (arr[j - 1] > arr[j]) {
        // swap numbers

        swap(arr, j, j - 1);
        _IS_ALIVE_
        emit updated({j - 1, j});
      }
    }
  }

  emit sorted();
}
