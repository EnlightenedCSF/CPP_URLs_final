#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include <QMdiSubWindow>
#include <QWidget>
//#include <QLabel>
//#include <QTableView>
#include <QtGui>
#include <QVector>
//#include <QStandardItemModel>

#include"linkrecord.h"
#include "resultwidget.h"

namespace Ui {
    class ChildWindow;
}

class ChildWindow : public QMdiSubWindow
{
    Q_OBJECT

public:
    explicit ChildWindow(QWidget *parent, QVector<LinkRecord*>* data);
    ~ChildWindow();

    QString getData();

private:
    ResultWidget* content_;

    //QVector<LinkRecord*>* data_;
};

#endif // CHILDWINDOW_H
