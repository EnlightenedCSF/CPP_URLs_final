#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QStringList>
#include <QHash>
#include <QVector>

//#include "linkrecord.h"
#include "analyzeresultdocument.h"

class FileParser
{
public:
    static AnalyzeResultDocument* parse(QString fileName);
    static AnalyzeResultDocument* parse(QStringList list);

    //static QHash<QString, QVector<LinkRecord*> >* parse(QString fileName);
    //static QHash<QString, QVector<LinkRecord*> >* parse(QStringList list);
};

#endif // FILEPARSER_H
