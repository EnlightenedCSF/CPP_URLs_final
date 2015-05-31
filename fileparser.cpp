#include "fileparser.h"
#include "iostream"

#include <QFile>
#include <QRegularExpression>
#include <QTextStream>

//QHash<QString, QVector<LinkRecord*> >* FileParser::parse(QString fileName) {
AnalyzeResultDocument* FileParser::parse(QString fileName) {

    QHash<QString, QVector<LinkRecord*> >* result = new QHash<QString, QVector<LinkRecord*> >();

    QFile inputFile(fileName);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        size_t lineNum = 1;
        QRegularExpression re("[a-zA-Z]{3,5}://([wW]{3}\\.)?(([a-zA-Z]([-_][a-zA-Z0-9]+|[a-zA-Z0-9]*)*)*\\.?([a-zA-Z]([-_][a-zA-Z0-9]+|[a-zA-Z0-9]*)*)+)*\\.[a-zA-Z]{2,6}(\\b|/|(/[a-zA-Z0-9_-]+)*/?)");

        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();

            QRegularExpressionMatchIterator it = re.globalMatch(line);
            while (it.hasNext()) {
                QRegularExpressionMatch match = it.next();

                QString captured = match.captured(0);
                if (result->contains(captured)) {
                    (*result)[captured].push_back(new LinkRecord(captured, fileName, lineNum));
                }
                else {
                    QVector<LinkRecord*> a;
                    a.push_back(new LinkRecord(captured, fileName, lineNum));
                    result->insert(captured, a);
                }
            }

            lineNum++;
        }
        inputFile.close();
    }

    return new AnalyzeResultDocument(result);
}

//QHash<QString, QVector<LinkRecord*> >* FileParser::parse(QStringList list) {
AnalyzeResultDocument* FileParser::parse(QStringList list) {

    QHash<QString, QVector<LinkRecord*> >* result = new QHash<QString, QVector<LinkRecord*> >();

    QHash<QString, QVector<LinkRecord*> >* links;
    for (int i = 0; i < list.size(); i++) {
        links = &(parse(list[i])->get());
        result->unite(*links);
    }

    //return result;
    return new AnalyzeResultDocument(result);
}
