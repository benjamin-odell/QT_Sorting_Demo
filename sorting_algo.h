#ifndef SORTING_ALGO_H
#define SORTING_ALGO_H

#include <QObject>
#include <vector>

class sorting_algo : public QObject
{
    Q_OBJECT
public:
    sorting_algo(int delay_time);

    virtual void sort(std::vector<int>& arr);

    void delay();

private:
    int delay_time;

signals:

    //signal for when the array is fully sorted
    void sorted();
    //singal for each iteration in the sorting algorithium
    void updated(int n);
};

#endif // SORTING_ALGO_H
