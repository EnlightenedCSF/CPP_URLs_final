#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "analyzeresultdocument.h"
#include "fileparser.h"
#include "childwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->toolBtnParse->setEnabled(false);

    ui->toolBtnSaveResultAs->setEnabled(false);
    ui->toolBtnClearResults->setEnabled(false);
    ui->toolBtnOpenResult->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getFileFolder(QString fullPath) {
    int index = fullPath.lastIndexOf('/');
    return fullPath.mid(0, index+1);
}

QString MainWindow::getFileName(QString fileName) {
    int index = fileName.lastIndexOf('/');
    return fileName.mid(index+1, fileName.length() - index);
}

void MainWindow::on_toolBtnOpenFiles_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      tr("Choose *.html files to analyze"),
                                                      "/home/enlightenedcsf/Projects/JSProjects/ajax/test/",
                                                      tr("HTML files (*.html)"));

    if (!files.empty()) {
        ui->lineEditFolder->setText( getFileFolder(files[0]) );
        for (int i = 0; i < files.size(); ++i)
            ui->listWidgetFilesToAnalyze->addItem( getFileName(files.at(i)) );
        ui->toolBtnParse->setEnabled(true);
    }
}



void MainWindow::on_toolBtnClearFileList_clicked()
{
    ui->lineEditFolder->clear();
    ui->listWidgetFilesToAnalyze->clear();
    ui->toolBtnParse->setEnabled(false);
}

void MainWindow::on_toolBtnParse_clicked()
{
    QStringList list;
    for (int i = 0; i < ui->listWidgetFilesToAnalyze->count(); i++){
        list.append( ui->lineEditFolder->text() + ui->listWidgetFilesToAnalyze->item(i)->text());
    }

    QHash<QString, QVector<LinkRecord*> >* data = &(FileParser::parse(list)->get());

    if (data->empty()) {
        QMessageBox::warning(this, "Warning", "Can't find any links to display", QMessageBox::Ok);
    }
    else {
        for (int i = 0; i < data->keys().size(); ++i) {
            QString s = data->keys()[i];
            QVector<LinkRecord*> value = (*data)[s];
            createChild(value);
        }

        ui->toolBtnSaveResultAs->setEnabled(true);
        ui->toolBtnClearResults->setEnabled(true);
        ui->toolBtnOpenResult->setEnabled(true);
    }
}

void MainWindow::createChild(QVector<LinkRecord*>& value) {

    ChildWindow *childWindow = new ChildWindow(ui->mdiArea, &value);
    childWindow->setAttribute(Qt::WA_DeleteOnClose);
    childWindow->show();
}

void MainWindow::on_toolBtnClearResults_clicked()
{
    if (ui->mdiArea->subWindowList().empty())
        return;

    for (int i = 0; i < ui->mdiArea->subWindowList().size(); i++) {
        ui->mdiArea->subWindowList().at(i)->hide();
    }
    ui->mdiArea->subWindowList().clear();

    ui->toolBtnSaveResultAs->setEnabled(false);
    ui->toolBtnClearResults->setEnabled(false);
    ui->toolBtnOpenResult->setEnabled(false);
}

void MainWindow::on_toolBtnSaveResultAs_clicked()
{
    if (ui->mdiArea->currentSubWindow() == 0)
        return;

    ChildWindow* selectedChild = dynamic_cast<ChildWindow*>(ui->mdiArea->currentSubWindow());
    if (selectedChild == 0)
        return;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save result content"), "", tr("Link Analyzer Format (*.laf);;All Files (*)"));
    if (fileName.isEmpty())
        return;

    QString content = selectedChild->getData();

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);

    QTextStream out(&file);
    out << content;
    file.close();
}

void MainWindow::on_toolBtnOpenResult_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      tr("Choose *.laf files to display"),
                                                      "/home/enlightenedcsf/Projects/JSProjects/ajax/test/",
                                                      tr("Link Analyzer Format (*.laf)"));

    if (!files.empty()) {

        //fuck this shit
//        ui->lineEditFolder->setText( getFileFolder(files[0]) );
//        for (int i = 0; i < files.size(); ++i)
//            ui->listWidgetFilesToAnalyze->addItem( getFileName(files.at(i)) );
//        ui->toolBtnParse->setEnabled(true);


    }
}
