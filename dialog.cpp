#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    hourPattern = QString("%1:%2");
    this->dateTime = "";
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_hours_sliderMoved(int position)
{
    ui->time->setText(QString(this->hourPattern).arg(position,2,10,QChar('0')).arg(ui->minutes->value(),2,10,QChar('0')));
    this->time = ui->time->text();
}

void Dialog::on_minutes_sliderMoved(int position)
{
    ui->time->setText(QString(this->hourPattern).arg(ui->hours->value(),2,10,QChar('0')).arg(position,2,10,QChar('0')));
    this->time = ui->time->text();
}

void Dialog::on_calendarWidget_clicked(const QDate &date)
{
    this->date = date.toString("yyyy-MM-dd");
}

void Dialog::on_pushButton_clicked()
{
    ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
    this->dateTime = QString("%1 %2").arg(this->date).arg(this->time);

    this->close();
}
