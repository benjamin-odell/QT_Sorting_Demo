# QT Sorting Demo

The aim of this project is to demonstrate various sorting algorithms using QT and C++.

## Overview

This program shows a step-by-step process for different sorting algorithms.
### Main Elements
* Algorithm selection box
    * Algorithms
        - Insertion
        - Selection
        - Bubble
        - Quick
        - Merge
        - Heap
* Input Box for custom list
    - Negative numbers not allowed
    - Separate numbers by any non-digit character
- Random button
    - Creates random list
    * Scroll box for random list size
        - Min: 5 
        - Max: 1000
- Sort / Stop
    - Starts the sorting animation or stops it based on context
## Sorting Algorithms

This application features six sorting algorithms.
### Insertion $O(n^2)$
Divides the array into two partitions: a sorted and an unsorted. The first element is assumed to be sorted. Starting with the second element: remove from unsorted partition, swap with elements in the sorted partition until element is in correct place. This proceeds until no elements are in the unsorted partition.

### Selection $O(n^2)$
Loops through the array finding the smallest element. Then swaps with the first element that hasn't been found this way. This process constructs the sorted array the way one might naturally try to do it, by picking the smallest element and then placing it at the beginning.
### Bubble $O(n^2)$
Loops through the array n times. During each iteration, loop through the array and swap each element with the previous element if the previous element is larger. This process places the largest element in the array at the end of the list. This in effect is almost the reverse of the selection sort, as you construct the array from the largest element to the smallest.
### Quick $O(n\log n)$ worst case: $O(n^2)$
A recursive sorting algorithm that first partitions the array. For this implementation it selects the last element in the array as the pivot, then you loop through the array placing elements that come after the pivot beyond it and elements that come before it before it. The pivot is now in the correct spot in the array.
You then recursively call the function on the upper and lower subtree. Quicksort suffers when the pivot is the largest or smallest element in the array. So if given a sorted array this Quicksort implementation would be $O(n^2)$ time complexity.
### Merge $O(n\log n)$
Merge sort splits the array into two new arrays. It then repeats this until the array has only one element. Since an array with one element is sorted, you can merge it with another sorted array to assemble a new sorted array. This then repeats until all elements are back in the original array, which is now sorted.
### Heap $O(n\log n)$
First you turn the array into a max heap. In a max heap the largest element is the first one. You then swap the last element with the first element. This puts the largest element in the array at the end. You then turn the rest of the array into a max heap again. This repeats until all the elements have been swapped, constructing the sorted array.

## Sources
* [QT](https://www.qt.io/)
* [QT Creator](https://www.qt.io/development/tools/qt-creator-ide)
* [Deep Seek (Grammar and Spelling in ReadMe)](https://chat.deepseek.com/share/jmum03o0ai5udbpsr8)