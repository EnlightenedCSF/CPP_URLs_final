#include "resultwidget.h"
#include "ui_resultwidget.h"

ResultWidget::ResultWidget(QWidget *parent, QVector<LinkRecord*>& data) :
    QWidget(parent),
    ui(new Ui::ResultWidget)
{
    ui->setupUi(this);

    model = new QStandardItemModel(1, 2, this);

    model->setHorizontalHeaderItem(0, new QStandardItem(QString("File")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Line number")));

    for (int i = 0; i < data.size(); ++i) {
        QList<QStandardItem *>* row = new QList<QStandardItem*>();

        row->append(new QStandardItem(data[i]->getFileName()));
        row->append(new QStandardItem(data[i]->getLine()));

        model->insertRow(i, *row);
    }
    ui->table->setModel(model);
    ui->urlLbl->setText(data[0]->getRef());
}

ResultWidget::~ResultWidget()
{
    delete ui;
}


QString ResultWidget::getData() {
    QString res = "";

    res += ui->urlLbl->text() + '\n';
    for (int i = 0; i < model->rowCount() - 1; i++) {
        res += model->item(i, 0)->text() + " " + model->item(i, 1)->text() + '\n';
    }

    return res;
}
