#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->_beginDateTime->setFocusPolicy(Qt::ClickFocus);
    ui->_beginDateTime->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog *dialog = new Dialog();
    dialog->exec();
    ui->_beginDateTime->setText(dialog->dateTime);
}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog *dialog = new Dialog();
    dialog->exec();
    ui->_endDateTime->setText(dialog->dateTime);
}
