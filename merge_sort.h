#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <QObject>
#include "sorting_algo.h"

class merge_sort : public sorting_algo
{
    Q_OBJECT
public:
    merge_sort(int d);
    void sort(std::vector<int>& arr) override;

private:
    //vector holding arrays used for merge sort
    std::vector<std::vector<int>*> arrs;
    void mergesort(std::vector<int>& arr);
    void merge(std::vector<int>& arr,std::vector<int>& a, std::vector<int>& b);
    void remove(std::vector<int>& arr);
};

#endif // MERGE_SORT_H
