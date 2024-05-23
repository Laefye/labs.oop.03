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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::push(char character) {
    ui->result->setText(ui->result->text() + character);
}

void MainWindow::clear() {
    ui->result->setText("");
}

void MainWindow::del() {
    ui->result->setText(ui->result->text().mid(0, ui->result->text().size() - 1));
}

void MainWindow::calculate() {
    try {
        std::string result = Facade().calculate(ui->result->text().toStdString());
        ui->result->setText(QString::fromStdString(result));
    } catch (InvalidExpressionException& err) {
        QMessageBox message;
        message.setText(err.what());
        message.exec();
    }
}
