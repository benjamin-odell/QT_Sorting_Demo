#include "merge_sort.h"

merge_sort::merge_sort(int d) : sorting_algo(d) {}

void merge_sort::sort(std::vector<int> &arr)
{
    mergesort(arr);
    emit sorted();
}

void merge_sort::mergesort(std::vector<int> &arr)
{
    //an array with one element is always sorted
    if(arr.size() <= 1)
        return;

    //remove array from list of arrays
    remove(arr);

    //split array into two sub arrays
    std::vector<int> l;
    std::vector<int> h;

    //get mid point
    int mid = arr.size() / 2;

    //copy element over to lower array
    for(int i = 0; i < mid; i++){
        l.push_back(arr[i]);
    }

    //copy elements over to upper part of the array
    for(int i = mid; i < arr.size(); i++){
        h.push_back(arr[i]);
    }

    //add both arrays to list of arrays
    arrs.push_back(&l);
    arrs.push_back(&h);

    //merge sort both arrays
    mergesort(l);
    mergesort(h);

    //combin arrays into sorted array
    merge(arr, l, h);

    //remove sub arrays from list of arrays
    remove(l);
    remove(h);

    //add sorted array back to the list of arrays
    arrs.push_back(&arr);
}

void merge_sort::merge(std::vector<int> &arr, std::vector<int> &a, std::vector<int> &b)
{

}

void merge_sort::remove(std::vector<int> &arr)
{
    //remove arr from arrs
    auto it = std::find(arrs.begin(),arrs.end(), &arr);
    if(it != arrs.end()){
        //erase element at that point
        arrs.erase(it);
    }
}
