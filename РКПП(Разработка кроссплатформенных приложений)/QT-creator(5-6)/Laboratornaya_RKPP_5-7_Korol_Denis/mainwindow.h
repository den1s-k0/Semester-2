#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QCloseEvent>


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

private slots:
    void on_Button_close_clicked();

    void closeEvent(QCloseEvent* event);

    void on_Button1_clicked();

    void on_Button1_1_clicked();

    void on_Button_2_clicked();

    void on_Button_2_1_clicked();

    void on_Button_3_clicked();

    void on_Button_3_1_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_Button_4_clicked();

    void on_Button_4_1_clicked();

    void on_Button_5_clicked();

    void on_Button_5_1_clicked();

    void on_Button_6_clicked();

    void on_Button_6_1_clicked();

    void on_Button_7_clicked();

    void on_Button_7_1_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
