# QT Sorting Demo

The aim of this project is the demo various sorting algorithms using QT and C++

## Overview

This application features six sorting algorithms.
### Insertion $O(n^2)$
Devides the array into two partitions: a sorted and an unsorted. The first element is assumed to be sorted. Starting with the second element: remove from unsorted partion, swap with elements in the sorted partion until element is in correct place. This procededs untill no elements are in the unsorted partition.

### Selection $O(n^2)$
Loops through array finding the smallest element. Then swap with the first element that hasn't been found this way. This process construct the sorted array the way one might natural try to do it, by picking the smallest element and then placing it a the begining.
### Bubble $O(n^2)$
Loops through the array n times. During each itiration loop through the array, and swap each element with the previous element if the previous element is larger. This process places the largers element in the array at the end of the list. This in effect is almost the reverse of the selection sort. As you construct the array from the largest element to the smallest.
### Quick $O(n\log n)$ worse case: $O(n^2)$
### Merge $O(n\log n)$
### Heap $O(n\log n)$

## Sources
* [QT](https://www.qt.io/)
* [QT Creator](https://www.qt.io/development/tools/qt-creator-ide)
