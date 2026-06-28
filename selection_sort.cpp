#include "selection_sort.h"

selection_sort::selection_sort(int t) : sorting_algo(t) {
    name = "Selection Sort";
}

void selection_sort::sort(std::vector<int> &arr)
{
    int min;
    int temp;
    for(int i = 0; i < arr.size(); i++){
        min = i;
        for(int j = i + 1; j < arr.size(); j++){
            //find smallest element
            if(arr[j] < arr[min]){
                //new smallest element
                min = j;
            }
            emit updated({j,i,min});
        }

        //swap with smallest element
        emit updated({i,min});
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        emit updated({min,i});
    }
    emit sorted();
}
