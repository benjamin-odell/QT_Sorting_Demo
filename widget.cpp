#include "widget.h"

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
    QBrush brush(Qt::blue);
    QPen pen(Qt::blue);


    //adds scene to view
    view->setScene(scene);

    //add a demo rectangle to the scene
    QGraphicsRectItem* temp_rect = scene->addRect(0,0,10,100,pen,brush);

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
