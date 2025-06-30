#include "mainwindow.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QList<int> qlist1 = {1, 2, 3, 4, 5};
    std::list<int> stdList1(qlist1.begin(), qlist1.end());
    QList<int> qlist2(stdList1.begin(), stdList1.end());
    for (int i = 0; i < qlist2.size(); ++i) {
        qDebug() << qlist2[i];
    }
    return a.exec();
}
