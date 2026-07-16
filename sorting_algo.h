#ifndef SORTING_ALGO_H
#define SORTING_ALGO_H
#define _IS_ALIVE_                                                             \
  if (!is_alive) {                                                             \
    return;                                                                    \
  }
#include <QObject>
#include <vector>

class sorting_algo : public QObject {
  Q_OBJECT
public:
  sorting_algo(int delay_time);

  void set_delay_time(double n);
  virtual void sort(std::vector<int> &arr);

  void delay();
  QString get_name();

  void set_alive(bool b);
  bool is_active();

private:
  double delay_time;

protected:
  QString name;
  bool is_alive = false;

  void swap(std::vector<int> &arr, int a, int b);

signals:

  // signal for when the array is fully sorted
  void sorted();
  // singal for each iteration in the sorting algorithium
  void updated(std::vector<int> n);
};

#endif // SORTING_ALGO_H
