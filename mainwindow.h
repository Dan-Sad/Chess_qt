#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QVariant>
#include <QPixmap>
#include <QListWidget>
#include <QtWidgets>
#include "label.h"
#include "chees.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   // chees* ch;
private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
