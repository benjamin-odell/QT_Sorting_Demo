#ifndef SORTING_ALGO_H
#define SORTING_ALGO_H

#include <QObject>
#include <vector>

class sorting_algo : QObject
{
    Q_OBJECT
public:
    sorting_algo();

    virtual void sort(std::vector<int>* arr);

signals:

    //signal for when the array is fully sorted
    void sorted();
    //singal for each iteration in the sorting algorithium
    void iteration();
};

#endif // SORTING_ALGO_H
