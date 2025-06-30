#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Создаем график
    QChart *chart = new QChart();
    chart->setTitle("Гиперболическая функция y = 1/x");

    // Устанавливаем темную тему
    chart->setTheme(QChart::ChartThemeDark);

    // Создаем серию данных для гиперболы y = 1/x
    QLineSeries *hyperbolaSeries = new QLineSeries();
    hyperbolaSeries->setName("y = 1/x");

    // Заполняем данными, избегая x = 0
    const double step = 0.1;
    const double range = 5.0;

    // Отрицательная ветвь
    for (double x = -range; x < -0.1; x += step) {
        hyperbolaSeries->append(x, 1.0/x);
    }

    // Положительная ветвь
    for (double x = 0.1; x <= range; x += step) {
        hyperbolaSeries->append(x, 1.0/x);
    }

    // Добавляем серию на график
    chart->addSeries(hyperbolaSeries);

    // Создаем и настраиваем оси
    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY = new QValueAxis();

    axisX->setRange(-range, range);
    axisY->setRange(-range-2, range+2); // +2 чтобы было место для асимптот

    axisX->setTitleText("Ось X");
    axisY->setTitleText("Ось Y");

    // Добавляем оси на график
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    // Привязываем серии к осям
    hyperbolaSeries->attachAxis(axisX);
    hyperbolaSeries->attachAxis(axisY);

    // Создаем линии осей X и Y (чтобы они проходили через 0,0)
    QLineSeries *xAxisLine = new QLineSeries();
    QLineSeries *yAxisLine = new QLineSeries();

    xAxisLine->append(-range, 0);
    xAxisLine->append(range, 0);

    yAxisLine->append(0, -range-2);
    yAxisLine->append(0, range+2);

    // Добавляем линии осей на график
    chart->addSeries(xAxisLine);
    chart->addSeries(yAxisLine);

    // Привязываем к осям
    xAxisLine->attachAxis(axisX);
    xAxisLine->attachAxis(axisY);
    yAxisLine->attachAxis(axisX);
    yAxisLine->attachAxis(axisY);

    // Настраиваем стиль линий осей (делаем их более заметными)
    QPen axisPen(Qt::white, 2.0);
    xAxisLine->setPen(axisPen);
    yAxisLine->setPen(axisPen);

    // Настраиваем стиль гиперболы
    QPen hyperbolaPen(QColor(255, 100, 100), 2.0); // Красноватый цвет
    hyperbolaPen.setStyle(Qt::SolidLine);
    hyperbolaSeries->setPen(hyperbolaPen);

    // Добавляем асимптоты (пунктирные линии)
    QLineSeries *asymptoteX = new QLineSeries(); // y=0
    asymptoteX->append(-range, 0);
    asymptoteX->append(range, 0);

    QLineSeries *asymptoteY = new QLineSeries(); // x=0
    asymptoteY->append(0, -range-2);
    asymptoteY->append(0, range+2);

    chart->addSeries(asymptoteX);
    chart->addSeries(asymptoteY);
    asymptoteX->attachAxis(axisX);
    asymptoteX->attachAxis(axisY);
    asymptoteY->attachAxis(axisX);
    asymptoteY->attachAxis(axisY);

    // Стиль асимптот
    QPen asymptotePen(Qt::gray, 1.0);
    asymptotePen.setStyle(Qt::DashLine);
    asymptoteX->setPen(asymptotePen);
    asymptoteY->setPen(asymptotePen);

    // Настраиваем легенду
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignTop);

    // Создаем view для отображения графика
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Размещаем в виджете из дизайнера
    ui->gridLayout_12->addWidget(chartView);
}

MainWindow::~MainWindow()
{
    delete ui;
}
