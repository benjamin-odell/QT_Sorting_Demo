#include "widget.h"
#include <vector>
#include "insertion_sort.h"
//#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //Init the window with inital paramiters
    setWindowTitle("Sorting Algo Test");
    //make window a good size
    resize(500,700);

    //Init our graphics scene and view
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);

    //Create our pens and brushes
    brush = QBrush(Qt::blue);
    pen = QPen(Qt::blue);


    //adds scene to view
    view->setScene(scene);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->addWidget(view);

    //Row for user input
    QHBoxLayout* input_row = new QHBoxLayout(this);

    //user input for numbers
    numbers = new QLineEdit(this);
    //Button to submit numbers
    submit = new QPushButton("Sort!", this);
    //Button to randomize the numbers
    random = new QPushButton("Randomize", this);
    //Spin box for random number
    rand_num = new QSpinBox(this);
    rand_num->setMinimum(3);
    rand_num->setMaximum(50);

    input_row->addWidget(rand_num);
    input_row->addWidget(random);
    input_row->addWidget(numbers);
    input_row->addWidget(submit);

    main_layout->addLayout(input_row);

    //set randomize button signal
    connect(random, SIGNAL(clicked()), this, SLOT(randomize()));

    //connect submit button to sort slot
    connect(submit, SIGNAL(clicked()),this, SLOT(sort()));

    //create test sorting object
    sorter = new insertion_sort(50);
    //connect test sorter to widget
    connect(sorter, SIGNAL(updated()), this, SLOT(update()));


    //update bars when you edit the line
    connect(numbers,SIGNAL(textChanged(QString)),this,SLOT(edit()));
}

Widget::~Widget() = default;

void Widget::randomize()
{
    int c = rand_num->value();
    //creates ten random numbers in the numbers object
    QString nums = "";
    for(int i = 0; i < c; i++){
        int n = (std::rand() % 15) + 1;
        //add a commad if not fist number
        if(i != 0)
            nums.append(",");
        nums.append(QVariant(n).toString());
    }

    //changes number text to show our numbers
    numbers->setText(nums);

    //updated the display
    create_bars();
}

void Widget::sort(){
    create_bars();
    //sort the list
    sorter->sort(nums);
}

void Widget::update()
{
    for(int i = 0; i < bars.size(); i++){
        bars[i]->setRect(QRect(i * 15,0,10, -10 * nums[i]));
    }


    //update view
    scene->update();
    view->update();

    sorter->delay();
}

void Widget::edit()
{
    create_bars();
}

void Widget::create_bars(){
    //clear scene
    clear();

    //get all the numbers from the numbers row
    QString s = numbers->text();
    QString n = "";
    bool is_number = false;
    for(QChar c : std::as_const(s)){
        //loop untill with find a QChar thats not a number
        if(c.isDigit())
        {
            n.append(c);
        }
        else
        {
            //add number to the nums row
            int num = n.toInt(&is_number);
            if(is_number) //makes sure that num is, in fact, a number
            {
                nums.push_back(num);
                //clear number
                n = "";
            }
        }
    }

    //add number to the nums row
    int num = n.toInt(&is_number);
    if(is_number) //makes sure that num is, in fact, a number
    {
        nums.push_back(num);
        //clear number
        n = "";
    }

    //after getting all of the numbers create the bars
    for(int i = 0; i < nums.size(); i++)
    {
        qDebug() << nums[i];
        bars.append(scene->addRect(i * 15,0,10,-10 * nums[i],pen,brush));
    }

    //update scene
    scene->update();
    view->update();
}

void Widget::clear()
{
    //delete all bars
    for(QGraphicsRectItem* b : std::as_const(bars)){
        scene->removeItem(b);
    }

    //clear bars
    bars.clear();
    //clear nums
    nums.clear();

    scene->clear();
}
