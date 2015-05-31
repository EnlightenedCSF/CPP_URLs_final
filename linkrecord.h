#ifndef LINKRECORD_H
#define LINKRECORD_H

#include <QString>

class LinkRecord
{
public:
    LinkRecord(QString href, QString where, size_t line);
    QString getRef();
    QString getFileName();
    QString getLine();

private:
    QString href_;
    QString fileName_;
    size_t line_;
};

#endif // LINKRECORD_H
