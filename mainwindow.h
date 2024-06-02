#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "facade.h"
#include "exceptions/invalidexpressionexception.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Facade facade;

    void updateUi();
    void push(char character);
    void clear();
    void del();
    void calculate();
    void run();
    void next();
    void stop();
    void mp();
    void mc();
    void mm();
    void mr();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
