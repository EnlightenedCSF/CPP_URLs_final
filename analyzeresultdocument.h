#ifndef ANALYZERESULTDOCUMENT_H
#define ANALYZERESULTDOCUMENT_H

#include <QHash>
#include <QString>
#include <QVector>

#include "linkrecord.h"

class AnalyzeResultDocument
{
public:
    AnalyzeResultDocument(QHash<QString, QVector<LinkRecord*> >* initData) : data_(initData) { }
    ~AnalyzeResultDocument() {
        for (QHash<QString, QVector<LinkRecord*> >::iterator i = data_->begin(); i != data_->end(); i++) {
            //...
        }
    }
    QHash<QString, QVector<LinkRecord*> >& get() {
        return *data_;
    }

private:
    QHash<QString, QVector<LinkRecord*> >* data_;
};

#endif // ANALYZERESULTDOCUMENT_H
