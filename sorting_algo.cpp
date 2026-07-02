#include "sorting_algo.h"
#include <QThread>
#include <QEventLoop>
#include <QTimer>

sorting_algo::sorting_algo(int delay_time) : delay_time(delay_time) {}

void sorting_algo::set_delay_time(int n)
{
    delay_time = n;
}

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

void sorting_algo::set_alive(bool b)
{
    is_alive = b;
}

bool sorting_algo::is_active()
{
    return is_alive;
}

void sorting_algo::swap(std::vector<int> &arr, int a, int b)
{
    //swap the two values
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
