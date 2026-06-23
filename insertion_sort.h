#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "sorting_algo.h"

class insertion_sort : public sorting_algo
{
public:
    insertion_sort(int delay_time);

    void sort(std::vector<int>& arr) override;
};

#endif // INSERTION_SORT_H
