#ifndef MYCHARTVIEW_H
#define MYCHARTVIEW_H

#include <QChartView >

class MyChartView : public QChartView
{
    Q_OBJECT
public:
    explicit MyChartView(QWidget *parent = nullptr);

};

#endif // MYCHARTVIEW_H
