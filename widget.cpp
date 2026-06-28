#include "widget.h"
#include <vector>
//#include <QDebug>
#include <QApplication>

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
    init_pens();


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
    rand_num->setMinimum(5);
    rand_num->setMaximum(50);

    input_row->addWidget(rand_num);
    input_row->addWidget(random);
    input_row->addWidget(numbers);
    input_row->addWidget(submit);

    //setup combo box
    combo_box = new QComboBox(this);
    combo_box->addItem("Insertion Sort", 0);
    combo_box->addItem("Selection Sort", 1);
    connect(combo_box,SIGNAL(currentIndexChanged(int)),this,SLOT(select_sort()));

    main_layout->addWidget(combo_box);
    main_layout->addLayout(input_row);

    //set randomize button signal
    connect(random, SIGNAL(clicked()), this, SLOT(randomize()));

    //connect submit button to sort slot
    connect(submit, SIGNAL(clicked()),this, SLOT(sort()));

    //create test sorting object
    sorter = insertion;
    //connect test sorter to widget
    connect(sorter, SIGNAL(updated(int,int)), this, SLOT(update(int,int)));
    connect(sorter,SIGNAL(sorted()),this,SLOT(sorted()));


    //update bars when you edit the line
    connect(numbers,SIGNAL(textChanged(QString)),this,SLOT(edit()));
}

Widget::~Widget() = default;

void Widget::randomize()
{
    //clear nums
    nums.clear();
    int c = rand_num->value();
    //creates c random numbers in the numbers object
    for(int i = 0; i < c; i++){
        int n = (std::rand() % (15 + c)) + 1;
        //add n to nums
        nums.push_back(n);
    }

    //change line edit text to match numbers
    add_nums_to_line_edit();
}

void Widget::sort(){
    create_bars();
    //sort the list
    numbers->setEnabled(false);
    sorter->sort(nums);
}

void Widget::update(int n, int w)
{
    for(int i = 0; i < bars.size(); i++){
        //reset all outlines to default
        bars[i]->setRect(i * 15,0,10,-10 * nums[i]);
        bars[i]->setPen(pens[0]);
    }



  //  add_nums_to_line_edit();
    if(w != -1){
        bars[w]->setPen(pens[2]);
    }


    //highlight currently selected bar
    bars[n]->setPen(pens[1]);



    //update view
    scene->update();
    view->update();

    //qApp->processEvents();

    sorter->delay();
}

void Widget::sorted()
{
    //loop through and change pen back to default
    for(int i = 0; i < bars.size(); i++){

        bars[i]->setPen(pens[0]);
    }

    //update scene
    scene->update();
    numbers->setEnabled(true);
}

void Widget::edit()
{
    create_bars();
}

void Widget::select_sort()
{
    Sort s = (Sort)combo_box->currentIndex();
    switch_sort(s);
}

void Widget::switch_sort(Sort s)
{
    //disconnect current sorter from all slots
    disconnect(sorter, SIGNAL(updated(int,int)), this, SLOT(update(int,int)));
    disconnect(sorter,SIGNAL(sorted()),this,SLOT(sorted()));

    switch(s){
    case INSERTION:
        sorter = insertion;
        break;
    case SELECTION:
        sorter = selection;
        break;
    }

    //connect new sorter to slots
    connect(sorter, SIGNAL(updated(int,int)), this, SLOT(update(int,int)));
    connect(sorter,SIGNAL(sorted()),this,SLOT(sorted()));
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
        bars.append(scene->addRect(i * 15,0,10,-10 * nums[i],pens[0],brush));
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

void Widget::add_nums_to_line_edit()
{
    QString text = "";
    for(int i = 0; i < nums.size(); i++){
        if(i != 0)
            text.append(",");

        text.append(QVariant(nums[i]).toString());
    }

    numbers->setText(text);
}

void Widget::init_pens()
{
    pens.append(QPen(Qt::blue));
    pens.append(QPen(Qt::yellow));
    pens.append(QPen(QColor("#e8ad55")));
}
