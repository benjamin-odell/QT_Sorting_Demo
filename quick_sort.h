#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <QObject>
#include "sorting_algo.h"

class quick_sort : public sorting_algo
{
    Q_OBJECT
public:
    quick_sort(int n);
    void sort(std::vector<int>& arr) override;

private:
    void quicksort(std::vector<int> &arr, int b, int e);
};

#endif // QUICK_SORT_H
