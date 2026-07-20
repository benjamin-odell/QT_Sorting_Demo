#include "widget.h"
#include <vector>
 #include <QDebug>
#include <QApplication>
#include <QSignalMapper>
#include <QIcon>
#include <QFile>

Widget::Widget(QWidget *parent) : QWidget(parent) {
  // Init the window with inital paramiters
  setWindowTitle("Sorting Algorithms");
  QIcon icon(":/icons/icon.svg");
  setWindowIcon(icon);

  // make window a good size
  resize(500, 700);

  // Init our graphics scene and view
  view = new QGraphicsView(this);
  scene = new QGraphicsScene(this);

  // Create our pens and brushes
  brush = QBrush(Qt::blue);
  init_pens();

  // adds scene to view
  view->setScene(scene);

  QVBoxLayout *main_layout = new QVBoxLayout(this);

  // make speed control buttons
  QHBoxLayout *speed_control_row = new QHBoxLayout(this);
  speed_up = new QPushButton(">", this);
  speed_down = new QPushButton("<", this);
  speed = new QLabel("1x");

  // setup slot connections
  connect(speed_up, &QPushButton::clicked, this, [this] { change_speed(2); });
  connect(speed_down, &QPushButton::clicked, this,
          [this] { change_speed(-2); });

  speed_control_row->addWidget(speed_down);
  speed_control_row->addWidget(speed);
  speed_control_row->addWidget(speed_up);
  speed_control_row->setAlignment(Qt::AlignRight);

  // add speed row to main layout
  main_layout->addLayout(speed_control_row);

  main_layout->addWidget(view);

  // Row for user input
  QHBoxLayout *input_row = new QHBoxLayout(this);

  // user input for numbers
  numbers = new QLineEdit(this);
  // Button to submit numbers
  submit = new QPushButton("Sort!", this);
  // Button to randomize the numbers
  random = new QPushButton("Randomize", this);
  // Spin box for random number
  rand_num = new QSpinBox(this);
  rand_num->setMinimum(5);
  rand_num->setMaximum(1000);

  input_row->addWidget(rand_num);
  input_row->addWidget(random);
  input_row->addWidget(numbers);
  input_row->addWidget(submit);

  // setup combo box
  combo_box = new QComboBox(this);
  combo_box->addItem("Insertion Sort");
  combo_box->addItem("Selection Sort");
  combo_box->addItem("Bubble Sort");
  combo_box->addItem("Quick Sort");
  combo_box->addItem("Merge Sort");
  combo_box->addItem("Heap Sort");
  connect(combo_box, SIGNAL(currentIndexChanged(int)), this,
          SLOT(select_sort()));

  main_layout->addWidget(combo_box);
  main_layout->addLayout(input_row);

  // set randomize button signal
  connect(random, SIGNAL(clicked()), this, SLOT(randomize()));

  // connect submit button to sort slot
  connect(submit, SIGNAL(clicked()), this, SLOT(sort()));

  // create test sorting object
  sorter = insertion;
  // connect test sorter to widget
  connect(sorter, SIGNAL(updated(std::vector<int>)), this,
          SLOT(update(std::vector<int>)));
  connect(sorter, SIGNAL(sorted()), this, SLOT(sorted()));

  // update bars when you edit the line
  connect(numbers, SIGNAL(textChanged(QString)), this, SLOT(edit()));
}

Widget::~Widget() = default;

void Widget::randomize() {
  // clear nums
  stop();
  nums.clear();
  int c = rand_num->value();
  // creates c random numbers in the numbers object
  for (int i = 0; i < c; i++) {
    int n = (std::rand() % (15 + c)) + 1;
    // add n to nums
    nums.push_back(n);
  }

  // change line edit text to match numbers
  add_nums_to_line_edit();
}

void Widget::sort() {
  // check if sorter is sorting
  if (sorter->is_active()) {
    stop();
    submit->setText("Sort!");
    return;
  }

  create_bars();

  // check to see if nums is empty
  if (nums.empty())
    return;
  // sort the list
  numbers->setEnabled(false);
  sorter->set_alive(true);
  submit->setText("Stop!");
  sorter->sort(nums);
  sorter->set_alive(false);
}

void Widget::update(std::vector<int> n) {
  int padding = 0;
  for (int i = 0; (i < bars.size() && (i + padding < nums.size())); i++) {
    // check if current value is zero
    if (nums[i + padding] == -1) {
      padding++;
      i--;
      continue;
    }

    // reset all outlines to default
    bars[i]->setRect((i + padding) * 15, 0, 10, -10 * nums[i + padding]);
    bars[i]->setPen(pens[0]);
  }

  // update outline of selected bars (backwards to avoid overlap)
  for (int i = n.size() - 1; i >= 0; i--) {
    if (n[i] >= 0)
      bars[n[i]]->setPen(pens[i + 1]);
  }
  delayed += delay_time;
  if (delayed >= 5) {
    fit();
    // update view
    scene->update();
    view->update();
    sorter->delay();

    delayed = 0;
  }
}

void Widget::sorted() {
  // change text back to sort
  submit->setText("Sort!");

  // loop through and change pen back to default
  for (int i = 0; i < bars.size(); i++) {

    bars[i]->setPen(pens[0]);
  }

  fit();

  // update scene
  scene->update();
  view->update();
  numbers->setEnabled(true);
}

void Widget::edit() {
  stop();
  create_bars();
}

void Widget::select_sort() {
  stop();
  Sort s = (Sort)combo_box->currentIndex();
  switch_sort(s);
}

void Widget::change_speed(int amt) {
  // change label
  int max_speed = 8192;
  QString s_time = speed->text();
  s_time.chop(1);
  int s = s_time.toInt();
  // change speed
  if (amt > 0)
    s *= amt;
  else
    s /= -amt;
  // don't let speed go below one
  if (s <= 1)
    s = 1;
  if (s >= max_speed)
    s = max_speed;

  // set delay time and update sorter
  delay_time = base_delay_time / s;
  sorter->set_delay_time(delay_time);

  speed->setText(QVariant(s).toString().append("x"));
}

void Widget::switch_sort(Sort s) {
  stop();
  // disconnect current sorter from all slots
  disconnect(sorter, SIGNAL(updated(std::vector<int>)), this,
             SLOT(update(std::vector<int>)));
  disconnect(sorter, SIGNAL(sorted()), this, SLOT(sorted()));

  switch (s) {
  case INSERTION:
    sorter = insertion;
    break;
  case SELECTION:
    sorter = selection;
    break;
  case BUBBLE:
    sorter = bubblesort;
    break;
  case QUICK:
    sorter = quicksort;
    break;
  case MERGE:
    sorter = mergesort;
    break;
  case HEAP:
    sorter = heapsort;
    break;
  }

  // ensure correct delay time
  sorter->set_delay_time(delay_time);

  // connect new sorter to slots
  connect(sorter, SIGNAL(updated(std::vector<int>)), this,
          SLOT(update(std::vector<int>)));
  connect(sorter, SIGNAL(sorted()), this, SLOT(sorted()));
  stop();
}

void Widget::stop() {
  sorter->set_alive(false);
  sorted();
  // reset sort to begining
  create_bars();
}

void Widget::fit() {
  // centers display on the bars
  QRectF rect = scene->itemsBoundingRect();
  scene->setSceneRect(QRectF(rect.left() - 50, rect.top() - 50,
                             rect.width() + 100, rect.height() + 50));
  view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void Widget::create_bars() {
  // clear scene
  clear();

  // get all the numbers from the numbers row
  QString s = numbers->text();
  QString n = "";
  bool is_number = false;
  for (QChar c : std::as_const(s)) {
    // loop untill with find a QChar thats not a number
    if (c.isDigit()) {
      n.append(c);
    } else {
      // add number to the nums row
      int num = n.toInt(&is_number);
      if (is_number) // makes sure that num is, in fact, a number
      {
        nums.push_back(num);
        // clear number
        n = "";
      }
    }
  }

  // add number to the nums row
  int num = n.toInt(&is_number);
  if (is_number) // makes sure that num is, in fact, a number
  {
    nums.push_back(num);
    // clear number
    n = "";
  }

  // after getting all of the numbers create the bars
  for (int i = 0; i < nums.size(); i++) {
    qDebug() << nums[i];
    bars.append(scene->addRect(i * 15, 0, 10, -10 * nums[i], pens[0], brush));
  }

  fit();

  // update scene
  scene->update();
  view->update();
}

void Widget::clear() {
  // delete all bars
  for (QGraphicsRectItem *b : std::as_const(bars)) {
    scene->removeItem(b);
  }

  // clear bars
  bars.clear();
  // clear nums
  nums.clear();

  scene->clear();
}

void Widget::add_nums_to_line_edit() {
  QString text = "";
  for (int i = 0; i < nums.size(); i++) {
    if (i != 0)
      text.append(",");

    text.append(QVariant(nums[i]).toString());
  }

  numbers->setText(text);
}

void Widget::init_pens() {
  pens.append(QPen(Qt::blue));
  pens.append(QPen(Qt::yellow));
  pens.append(QPen(QColor("#b25310")));
  pens.append(QPen(QColor("#e27f8f")));
}
