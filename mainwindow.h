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
    void push(char character);
    void clear();
    void del();
    void calculate();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
