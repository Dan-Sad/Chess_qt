#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QListWidget>
#include <QtWidgets>

class Label : public QLabel
{
    Q_OBJECT
public:
    explicit Label(QWidget *parent = nullptr);
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // LABEL_H
