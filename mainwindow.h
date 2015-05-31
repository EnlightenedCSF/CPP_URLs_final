#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "linkrecord.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolBtnOpenFiles_clicked();

    void on_toolBtnClearFileList_clicked();

    void on_toolBtnParse_clicked();

    void on_toolBtnClearResults_clicked();

    void on_toolBtnSaveResultAs_clicked();

    void on_toolBtnOpenResult_clicked();

private:
    Ui::MainWindow *ui;

    QString getFileFolder(QString fullPath);
    QString getFileName(QString fileName);

    void createChild(QVector<LinkRecord*>& value);
};

#endif // MAINWINDOW_H
