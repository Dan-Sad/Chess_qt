#include "label.h"

Label::Label(QWidget *parent) : QLabel(parent)
{
}

void Label::mousePressEvent(QMouseEvent *event)
{
    QMessageBox msgBox;
    QString str = "Номер клетки:  ", str2 = objectName();
    str.append(str2);
    msgBox . setText (str);
    msgBox . exec ();
}
