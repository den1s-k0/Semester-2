#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QScrollArea>
#include <QWidget>
#include <QList>
#include <QLabel>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
QList<quint16> lst1, lst2;
QList<quint16>* lst = &lst1;

void MainWindow::on_Button_close_clicked()
{
    QMessageBox::StandardButton close1 =  QMessageBox::question(this, "Закрытие программы", "Вы действительно хотите закрыть программу?",
                                                               QMessageBox::Yes | QMessageBox::No);
    if(close1 == QMessageBox::Yes)
        QApplication::quit();
    else {}
}

void MainWindow::closeEvent(QCloseEvent* event){
    QMessageBox::StandardButton close1 =  QMessageBox::question(this, "Закрытие программы", "Вы действительно хотите закрыть программу?",
                                                               QMessageBox::Yes | QMessageBox::No);
    if(close1 == QMessageBox::Yes)
        event->accept();
    else {
        event->ignore();
    }
}

void MainWindow::on_Button1_clicked()
{
    if(lst->empty()){
        ui->stackedWidget->hide();
        QMessageBox::about(this, "QList", "Список пуст");
    }
    else{
        ui->stackedWidget->setCurrentIndex(0);
        ui->label_1->clear();
        ui->stackedWidget->show();
        for(int i = 0; i < lst->size(); i++){
            if(i != 0) ui->label_1->setText(ui->label_1->text() + "\n");
            ui->label_1->setText(ui->label_1->text() + QString::number(i + 1) + ": " + QString::number((*lst)[i]));
        }
    }
}

void MainWindow::on_Button1_1_clicked()
{
    ui->stackedWidget->hide();
}

void MainWindow::on_Button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->Button_2_1->setText("OK");
    ui->stackedWidget->show();
}

void MainWindow::on_Button_2_1_clicked()
{
    if(ui->lineEdit_2->text() == nullptr){
        ui->stackedWidget->hide();
    }
    else{
        if((ui->lineEdit_2->text()).toInt() > 65535 || (ui->lineEdit_2->text()).toInt() < 0){
            ui->lineEdit_2->clear();
            ui->Button_2_1->setText("OK");
            QMessageBox::about(this, "QList", "Элемент не помещается в quint16\nПопробуйте другое число");
        }
        else{
            quint16 A = (ui->lineEdit_2->text()).toInt();
            lst->append(A);
            ui->Button_2_1->setText("Элемент добавлен");
            ui->lineEdit_2->clear();
        }
    }
}

void MainWindow::on_Button_3_clicked()
{
    if(lst->empty()){
        ui->stackedWidget->hide();
        QMessageBox::about(this, "QList", "Список пуст");
    }
    else{
    ui->stackedWidget->setCurrentIndex(2);
    ui->Button_3_1->setText("OK");
    ui->stackedWidget->show();
    }
}

void MainWindow::on_Button_3_1_clicked()
{
    if(ui->lineEdit_3->text() == nullptr){
        ui->stackedWidget->hide();
    }
    else{
        if((ui->lineEdit_3->text()).toInt() > lst->size() || (ui->lineEdit_3->text()).toInt() < 1){
            ui->lineEdit_3->clear();
            ui->Button_3_1->setText("OK");
            QMessageBox::about(this, "QList", "Индекс за границами списка");
        }
        else{
            lst->removeAt((ui->lineEdit_3->text()).toInt() - 1);
            ui->Button_3_1->setText("Элемент удален");
            ui->lineEdit_3->clear();
        }
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if(ui->spinBox->value()== 1) {
        ui->label_0->setText("QList - 1");
        lst = &lst1;
    }
    if(ui->spinBox->value() == 2) {
        ui->label_0->setText("QList - 2");
        lst = &lst2;
    }
    ui->stackedWidget->hide();
}

void MainWindow::on_Button_4_clicked()
{
    if(lst->empty()){
        ui->stackedWidget->hide();
        QMessageBox::about(this, "QList", "Список пуст");
    }
    else{
        ui->stackedWidget->setCurrentIndex(3);
        ui->stackedWidget->show();
        int mult = 1;
        for(int i = 0; i < lst->size(); i++)
            mult *= (*lst)[i];
        ui->label_4->setText("Произведение всех элементов \nсписка = " + QString::number(mult));
    }
}

void MainWindow::on_Button_4_1_clicked()
{
    ui->stackedWidget->hide();
}

void MainWindow::on_Button_5_clicked()
{
    if(lst1.empty() && lst2.empty()){
        ui->stackedWidget->hide();
        QMessageBox::about(this, "QList", "Оба списка пусты");
    }
    else{
        ui->stackedWidget->setCurrentIndex(4);
        ui->label_6->setText("Содержимое списка QList-2\n будет перенесено в QList 1");
        ui->stackedWidget->show();
    }
}

void MainWindow::on_Button_5_1_clicked()
{
    if(ui->label_6->text() == "Списки объеденины"){
        ui->stackedWidget->hide();
    }
    else{
        if(!lst2.empty()){
            QMessageBox::StandardButton ob =  QMessageBox::question(this, "QList", "Вы действительно хотите объеденить списки?",
                                                                       QMessageBox::Yes | QMessageBox::No);
            if(ob == QMessageBox::Yes){
                lst1.append(lst2);
                ui->label_6->setText("Списки объеденины");
            }
            else {}
        }
        else{
            ui->label_6->setText("Списки объеденины");
        }
    }
}

void MainWindow::on_Button_6_clicked()
{
    if(lst->empty()){
        ui->stackedWidget->hide();
        QMessageBox::about(this, "QList", "Список пуст");
    }
    else{
        ui->stackedWidget->setCurrentIndex(5);
        ui->label_5->setText("Введите номер элемента,\nв котором хотите посчитатть нули");
        ui->stackedWidget->show();
    }
}

void MainWindow::on_Button_6_1_clicked()
{
    if(ui->lineEdit_6->text() == nullptr){
        ui->stackedWidget->hide();
    }
    else{
        if((ui->lineEdit_6->text()).toInt() > lst->size() || (ui->lineEdit_6->text()).toInt() < 1){
            ui->lineEdit_6->clear();
            QMessageBox::about(this, "QList", "Индекс за границами списка");
        }
        else{
            int zeros = qCountTrailingZeroBits((*lst)[(ui->lineEdit_6->text()).toInt() - 1]);
            ui->label_5->setText("Количество нулей = " + QString::number(zeros));
            ui->lineEdit_6->clear();
        }
    }
}

void MainWindow::on_Button_7_clicked()
{
    if(lst->empty()){
        ui->stackedWidget->hide();
        QMessageBox::about(this, "QList", "Список пуст");
    }
    else{
        ui->stackedWidget->setCurrentIndex(6);
        ui->Button_7_1->setText("OK");
        ui->stackedWidget->show();
    }
}

void MainWindow::on_Button_7_1_clicked()
{
    if(ui->lineEdit_7->text() == nullptr && ui->lineEdit_7_2->text() == nullptr){
        ui->stackedWidget->hide();
    }
    else{
        if(ui->lineEdit_7->text() == nullptr || ui->lineEdit_7_2->text() == nullptr){
            QMessageBox::StandardButton prop =  QMessageBox::information(this, "QList", "Вы заполнили не все поля");
        }
        else{
            if((ui->lineEdit_7->text()).toInt() > lst->size() || (ui->lineEdit_7->text()).toInt() < 1){
                ui->lineEdit_7->clear();
                ui->Button_7_1->setText("OK");
                QMessageBox::about(this, "QList", "Индекс за границами списка");
            }
            else{
                if((ui->lineEdit_7_2->text()).toInt() > 65535 || (ui->lineEdit_7_2->text()).toInt() < 0){
                    ui->lineEdit_7_2->clear();
                    ui->Button_7_1->setText("OK");
                    QMessageBox::about(this, "QList", "Элемент не помещается в quint16\nПопробуйте другое число");
                }
                else{
                    lst->replace((ui->lineEdit_7->text()).toInt() - 1, (ui->lineEdit_7_2->text()).toInt());
                    ui->Button_7_1->setText("Элемент заменен");
                    ui->lineEdit_7->clear();
                    ui->lineEdit_7_2->clear();
                }
            }
        }
    }
}

