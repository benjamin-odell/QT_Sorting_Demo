#include "widget.h"
#include <vector>
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

    //add a demo rectangle to the scene
    QGraphicsRectItem* temp_rect = scene->addRect(0,0,10,-10,pen,brush);

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

    input_row->addWidget(random);
    input_row->addWidget(numbers);
    input_row->addWidget(submit);

    main_layout->addLayout(input_row);

    //set randomize button signal
    connect(random, SIGNAL(clicked()), this, SLOT(randomize()));

    //connect submit button to sort slot
    connect(submit, SIGNAL(clicked()),this, SLOT(sort()));

}

Widget::~Widget() = default;

void Widget::randomize()
{
    //creates ten random numbers in the numbers object
    QString nums = "";
    for(int i = 0; i < 10; i++){
        int n = (std::rand() % 15) + 1;
        //add a commad if not fist number
        if(i != 0)
            nums.append(",");
        nums.append(QVariant(n).toString());
    }

    //changes number text to show our numbers
    numbers->setText(nums);
}

void Widget::sort(){
    clear();
    create_bars();
    //view->update();
    scene->update();
    view->update();
}

void Widget::create_bars(){
    //get all the numbers from the numbers row
    QString s = numbers->text();
    QString n = "";
    std::vector<int> nums;
    bool is_number = false;
    for(QChar c : std::as_const(s)){
        //loop untill with find a QChar thats not a number
        if(c.isNumber())
        {
            n += c;
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

        //add number to the nums row
        int num = n.toInt(&is_number);
        if(is_number) //makes sure that num is, in fact, a number
        {
            nums.push_back(num);
            //clear number
            n = "";
        }
    }

    //after getting all of the numbers create the bars
    for(int i = 0; i < nums.size(); i++)
    {
        qDebug() << nums[i];
        bars.append(scene->addRect(i * 15,0,10,-10 * nums[i],pen,brush));
    }
}

void Widget::clear()
{
    //delete all bars
    for(QGraphicsRectItem* b : std::as_const(bars)){
        scene->removeItem(b);
    }

    //clear bars
    bars.clear();

    scene->clear();
}
