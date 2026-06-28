#include "sorting_algo.h"
#include <QThread>
#include <QEventLoop>
#include <QTimer>

sorting_algo::sorting_algo(int delay_time) : delay_time(delay_time) {}

void sorting_algo::sort(std::vector<int> &arr)
{

}

void sorting_algo::delay()
{
    QEventLoop loop;
    QTimer::singleShot(delay_time,&loop, &QEventLoop::quit);
    loop.exec();
}

QString sorting_algo::get_name()
{
    return name;
}
