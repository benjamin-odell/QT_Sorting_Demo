#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <QObject>
#include "sorting_algo.h"

class selection_sort : public sorting_algo
{
    Q_OBJECT
public:
    selection_sort(int t);

    void sort(std::vector<int>& arr) override;
};

#endif // SELECTION_SORT_H
