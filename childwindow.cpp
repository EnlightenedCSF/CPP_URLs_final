#include "childwindow.h"

#include <sstream>
//#include <QStringBuilder>

ChildWindow::ChildWindow(QWidget *parent, QVector<LinkRecord*>* data) :
    QMdiSubWindow(parent)
{
    //data_ = data;
    content_ = new ResultWidget(this, *data);
    this->setWidget(content_);
}

ChildWindow::~ChildWindow()
{
    content_->~ResultWidget();
}

QString ChildWindow::getData() {
    return content_->getData();
}
