#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    p =new QProcess(this);
    QPushButton *bt = new QPushButton("execute notepad", this);
    connect(bt,SIGNAL(clicked()),this,SLOT(openProcess()));
}

MainWindow::~MainWindow()
{

}
void MainWindow::openProcess()
{
    p->start("Tc.exe", QStringList() << "E:\\Test\\Addin\\zxjt_v6(6.53)\\Tc.exe" << "dir");
    p->start("E:\\Test\\Addin\\zxjt_v6(6.53)\\Tc.exe");
     connect(p, SIGNAL(finished(int)), this, SLOT(readResult(int)));
}

void MainWindow::readResult(int exitCode)
{
    if(exitCode == 0) {
        QTextCodec* gbkCodec = QTextCodec::codecForName("GBK");
        QString result = gbkCodec->toUnicode(p->readAll());
        QMessageBox::information(this, "dir", result);
    }
}
