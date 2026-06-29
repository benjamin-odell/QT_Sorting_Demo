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
    QString get_name();

private:
    int delay_time;

protected:
    QString name;

    void swap(std::vector<int> &arr, int a, int b);

signals:

    //signal for when the array is fully sorted
    void sorted();
    //singal for each iteration in the sorting algorithium
    void updated(std::vector<int> n);
};

#endif // SORTING_ALGO_H
