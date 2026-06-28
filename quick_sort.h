#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <QObject>
#include "sorting_algo.h"

class quick_sort : public sorting_algo
{
    Q_OBJECT
public:
    quick_sort(int n);
};

#endif // QUICK_SORT_H
