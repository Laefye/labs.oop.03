#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->d0, &QPushButton::clicked, this, [this]() {push('0');});
    connect(ui->d1, &QPushButton::clicked, this, [this]() {push('1');});
    connect(ui->d2, &QPushButton::clicked, this, [this]() {push('2');});
    connect(ui->d3, &QPushButton::clicked, this, [this]() {push('3');});
    connect(ui->d4, &QPushButton::clicked, this, [this]() {push('4');});
    connect(ui->d5, &QPushButton::clicked, this, [this]() {push('5');});
    connect(ui->d6, &QPushButton::clicked, this, [this]() {push('6');});
    connect(ui->d7, &QPushButton::clicked, this, [this]() {push('7');});
    connect(ui->d8, &QPushButton::clicked, this, [this]() {push('8');});
    connect(ui->d9, &QPushButton::clicked, this, [this]() {push('9');});
    connect(ui->point, &QPushButton::clicked, this, [this]() {push('.');});
    connect(ui->add, &QPushButton::clicked, this, [this]() {push('+');});
    connect(ui->minus, &QPushButton::clicked, this, [this]() {push('-');});
    connect(ui->divide, &QPushButton::clicked, this, [this]() {push('/');});
    connect(ui->multiply, &QPushButton::clicked, this, [this]() {push('*');});
    connect(ui->openBracket, &QPushButton::clicked, this, [this]() {push('(');});
    connect(ui->closeBracket, &QPushButton::clicked, this, [this]() {push(')');});
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->del, &QPushButton::clicked, this, &MainWindow::del);
    connect(ui->equals, &QPushButton::clicked, this, &MainWindow::calculate);
    connect(ui->next, &QPushButton::clicked, this, &MainWindow::next);
    connect(ui->stop, &QPushButton::clicked, this, &MainWindow::stop);
    connect(ui->run, &QPushButton::clicked, this, &MainWindow::run);
    connect(ui->mc, &QPushButton::clicked, this, &MainWindow::mc);
    connect(ui->mr, &QPushButton::clicked, this, &MainWindow::mr);
    connect(ui->mp, &QPushButton::clicked, this, &MainWindow::mp);
    connect(ui->mm, &QPushButton::clicked, this, &MainWindow::mm);

    updateUi();
}

void showError(std::exception* exception) {
    QMessageBox message;
    message.setText(exception->what());
    message.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::push(char character) {
    facade.setExpression((ui->result->text() + character).toStdString());
    updateUi();
}

void MainWindow::clear() {
    facade.setExpression("");
    updateUi();
}

void MainWindow::del() {
    facade.setExpression(ui->result->text().mid(0, ui->result->text().size() - 1).toStdString());
    updateUi();
}

void MainWindow::updateUi() {
    ui->d0->setEnabled(!facade.isCommands());
    ui->d1->setEnabled(!facade.isCommands());
    ui->d2->setEnabled(!facade.isCommands());
    ui->d3->setEnabled(!facade.isCommands());
    ui->d4->setEnabled(!facade.isCommands());
    ui->d5->setEnabled(!facade.isCommands());
    ui->d6->setEnabled(!facade.isCommands());
    ui->d7->setEnabled(!facade.isCommands());
    ui->d8->setEnabled(!facade.isCommands());
    ui->d9->setEnabled(!facade.isCommands());
    ui->point->setEnabled(!facade.isCommands());
    ui->add->setEnabled(!facade.isCommands());
    ui->minus->setEnabled(!facade.isCommands());
    ui->divide->setEnabled(!facade.isCommands());
    ui->multiply->setEnabled(!facade.isCommands());
    ui->openBracket->setEnabled(!facade.isCommands());
    ui->closeBracket->setEnabled(!facade.isCommands());
    ui->clear->setEnabled(!facade.isCommands());
    ui->del->setEnabled(!facade.isCommands());
    ui->equals->setEnabled(!facade.isCommands());
    ui->run->setEnabled(!facade.isCommands());
    ui->next->setEnabled(facade.isCommands());
    ui->stop->setEnabled(facade.isCommands());
    ui->mr->setEnabled(!facade.isCommands());
    ui->result->setText(QString::fromStdString(facade.getExpression()));
}

void MainWindow::calculate() {
    try {
        facade.calculate();
    } catch (InvalidExpressionException& err) {
        showError(&err);
    }
    updateUi();
}

void MainWindow::run() {
    try {
        facade.run();
        next();
    } catch (InvalidExpressionException& err) {
        showError(&err);
    }
    updateUi();
}

void MainWindow::next() {
    facade.next();
    updateUi();
}

void MainWindow::stop() {
    facade.stop();
    updateUi();
}

void MainWindow::mc() {
    facade.mc();
    updateUi();
}

void MainWindow::mr() {
    try {
        facade.mr();
    } catch (InvalidExpressionException& err) {
        showError(&err);
    }
    updateUi();
}
void MainWindow::mp() {
    try {
        facade.mp();
    } catch (InvalidExpressionException& err) {
        showError(&err);
    }
    updateUi();
}
void MainWindow::mm() {
    try {
        facade.mm();
    } catch (InvalidExpressionException& err) {
        showError(&err);
    }
    updateUi();
}
