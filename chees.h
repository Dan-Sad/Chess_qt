#ifndef CHEES_H
#define CHEES_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QListWidget>
#include <QtWidgets>
#include <QTextStream>
#include "label.h"

class chees : public QWidget
{
    Q_OBJECT
public:
    explicit chees(QWidget *parent = nullptr);

    QString str, str2;
    QGridLayout* GLayout;
    Label* lab[8][8];
    QPixmap mypix;
    QLineEdit* lineEdit_1;
    QLineEdit* lineEdit_2;
    int first, two, first_2, two_2;

    void figures(int i, int j);
    void slot();
    void work();
private slots:
    void read();
    void read_2();
    void png_name();

signals:

};

#endif // CHEES_H
