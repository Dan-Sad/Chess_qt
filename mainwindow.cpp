#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   this->setWindowTitle(QApplication::translate("Chess", "Chess", nullptr));

   connect (ui->pushButton, SIGNAL(clicked()), ui->label, SLOT(png_name()));
  // ch = new chees;
  // this->setCentralWidget(ch);
}

MainWindow::~MainWindow()
{
  delete ui;
}

