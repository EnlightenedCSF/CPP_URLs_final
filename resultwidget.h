#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QVector>

#include "linkrecord.h"

namespace Ui {
class ResultWidget;
}

class ResultWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ResultWidget(QWidget *parent, QVector<LinkRecord*>& data);    
    ~ResultWidget();

    QString getData();

private:
    Ui::ResultWidget *ui;

    QStandardItemModel *model;
};

#endif // RESULTWIDGET_H
