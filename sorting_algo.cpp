#include "sorting_algo.h"
#include <QTime>
#include <QThread>

sorting_algo::sorting_algo(int delay_time) : delay_time(delay_time) {}

void sorting_algo::sort(std::vector<int> &arr)
{

}

void sorting_algo::delay()
{
    QThread::msleep(delay_time);
    return;
}

QString sorting_algo::get_name()
{
    return name;
}
