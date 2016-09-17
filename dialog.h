#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString dateTime;
    QString date;
    QString time;

private slots:
    void on_hours_sliderMoved(int position);

    void on_minutes_sliderMoved(int position);

    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QString hourPattern;
};

#endif // DIALOG_H
