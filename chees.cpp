#include "chees.h"

chees::chees(QWidget *parent) //: QWidget(parent)
  : first(0), two(0), first_2(0), two_2(0)
{
    this->setParent(parent);

    GLayout = new QGridLayout;

    GLayout->setContentsMargins(5, 5, 5, 5);

    for (int i = 0; i<8; i++)
    {
        for (int j = 0; j<8; j++)
        {
            lab[i][j] = new Label;
            str.setNum(i+1);
            str.append(", ");
            str2.setNum(j+1);
            str.append(str2);
            lab[i][j] -> setObjectName(str);
            lab[i][j] -> setMinimumSize(60, 60);

            if ((i + j) % 2 == 0)
            {
                lab[i][j] -> setStyleSheet("background-color: white;");
            }else
            {
                lab[i][j] -> setStyleSheet("background-color: green;");
            }
            figures (i, j);

            GLayout->addWidget(lab[i][j], i, j);
        }
    }

    slot();

    this -> setLayout(GLayout);
}

void chees :: slot()
{
    QLabel* label = new QLabel("Select shape:");
    label -> setStyleSheet("font-size: 25px");
    GLayout->addWidget(label, 4, 8);

    QLabel* label_start = new QLabel("Specify the starting coordinates: (i j)");
    label_start -> setStyleSheet("font-size: 20px");
    GLayout->addWidget(label_start, 0, 8);

    QLabel* label_end = new QLabel("Specify the end coordinates: (i j)");
    label_end -> setStyleSheet("font-size: 20px");
    GLayout->addWidget(label_end, 1, 8);

    lineEdit_1 = new QLineEdit("");
    lineEdit_2 = new QLineEdit("");

    connect(lineEdit_1, SIGNAL(textChanged(QString)), this, SLOT(read()));
    connect(lineEdit_2, SIGNAL(textChanged(QString)), this, SLOT(read_2()));

    GLayout->addWidget(lineEdit_1, 0, 9);
    GLayout->addWidget(lineEdit_2, 1, 9);

   // QPushButton *pButton = new QPushButton("SELECT SHAPE");
    //connect(pButton, SIGNAL(clicked()), this, SLOT(png_name()));
   // GLayout->addWidget(pButton, 3, 8);
}

void chees :: work()
{
    mypix.load(":/pawn_w.png");
    lab[first][two] -> setPixmap(mypix.scaled(QSize(1, 1)));
}

void chees :: png_name()
{
    if (!(first == 0 || two == 0))
    {
        work();
    }
    if (!(first_2 == 0 || two_2 == 0))
    {
        QString img = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.png *.jpg");
        QPixmap pix(img);
        lab[first_2][two_2] -> setPixmap(pix.scaled(QSize(60, 60)));
    }else
    {
        QMessageBox msgBox;
        QString str = "Нет конечных координат!", str2 = objectName();
        str.append(str2);
        msgBox . setText (str);
        msgBox . exec ();
    }
}

void chees :: read()
{
    QString str = lineEdit_1 -> text();
    QString str_1 = str;
    str.remove(1,5);
    first = str.toInt() - 1;
    str_1.remove(0,2);
    str_1.remove(1,5);
    two = str_1.toInt() - 1;
}

void chees :: read_2()
{
    QString str = lineEdit_2 -> text();
    QString str_1 = str;
    str.remove(1,5);
    first_2 = str.toInt() - 1;
    str_1.remove(0,2);
    str_1.remove(1,5);
    two_2 = str_1.toInt() - 1;
}

void chees :: figures(int i, int j)
{
    if (i == 1)
    {
        mypix.load(":/pawn_w.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
    if (i == 6)
    {
        mypix.load(":/pawn.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
    if (i == 0 && (j == 0 || j == 7))
    {
        mypix.load(":/rook_w.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
    if (i == 7 && (j == 0 || j == 7))
    {
        mypix.load(":/rook.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
    if (i == 0 && (j == 1 || j == 6))
    {
        mypix.load(":/hourse_w.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
    if (i == 7 && (j == 1 || j == 6))
    {
        mypix.load(":/hourse.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
    if (i == 0 && (j == 2 || j == 5))
    {
        mypix.load(":/slon_w.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
    if (i == 7 && (j == 2 || j == 5))
    {
        mypix.load(":/slon.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
    if (i == 0 && j == 3)
    {
        mypix.load(":/queen_w.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
    if (i == 7 && j == 3)
    {
        mypix.load(":/queen.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
    if (i == 0 && j == 4)
    {
        mypix.load(":/king_w.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
    if (i == 7 && j == 4)
    {
        mypix.load(":/king.png");
        lab[i][j] -> setPixmap(mypix.scaled(QSize(60, 60)));
    }
}
