#include "quick_sort.h"

quick_sort::quick_sort(int n) : sorting_algo(n) {}

void quick_sort::sort(std::vector<int> &arr)
{
    //call quick sort for the whole array
    quicksort(arr,0, arr.size());
    _IS_ALIVE_
    emit sorted();
}

void quick_sort::quicksort(std::vector<int> &arr,int b, int e)
{
    if(e <= b)
        return;

    //first partion the array
    int pivot = e - 1;
    int lp = b-1;



    for(int i = b; i < e; i++){
        _IS_ALIVE_
        emit updated({i,lp,pivot});
        if(arr[i] < arr[pivot]){
            //increment pointer
            lp++;
            //swap values
            swap(arr,lp,i);
            _IS_ALIVE_
            emit updated({i,lp,pivot});
        }
    }
    //swap pivot with left
    lp++;
   // emit updated({pivot,lp});
    swap(arr,lp,pivot);
    _IS_ALIVE_
    emit updated({lp});

    //quick sort upper and lower partions
    quicksort(arr,b,lp);
    quicksort(arr,lp+1,e);
}
