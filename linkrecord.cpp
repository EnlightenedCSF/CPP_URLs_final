#include "linkrecord.h"

LinkRecord::LinkRecord(QString href, QString where, size_t line) : href_(href), fileName_(where), line_(line) {}

QString LinkRecord::getRef() {
    return href_;
}

QString LinkRecord::getFileName() {
    return fileName_;
}

QString LinkRecord::getLine() {
    return QString::number(line_);
}
