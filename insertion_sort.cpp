#include "insertion_sort.h"

insertion_sort::insertion_sort(int delay_time) : sorting_algo(delay_time) {
    name = "Insertion Sort";
}

void insertion_sort::sort(std::vector<int> &arr)
{
    std::vector<int> n;
    for(int i = 1; i < arr.size(); i++){
        emit updated({i, i-1});
        if(arr[i] < arr[i-1]){
            //loop through the array until you find a value that it is larger than
            int j = i;
           // emit updated(j,j-1);
            while(j > 0 && arr[j] < arr[j-1]){
                emit updated({j,j-1});
                //swap the points
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
                emit updated({j, j+1});
               // delay();
            }
        }
    }
    int t = arr.size() - 1;
    emit updated({t});
    emit sorted();
}


