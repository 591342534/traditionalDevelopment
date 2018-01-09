#ifndef REALTIMECURVEQCHARTWIDGET_H
#define REALTIMECURVEQCHARTWIDGET_H

#include <QWidget>
#include <QSplineSeries>
#include <QScatterSeries>
#include <QStackedBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QChart>
#include <QChartView>
#include <QValueAxis>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>

using namespace QtCharts;

class RealTimeCurveQChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RealTimeCurveQChartWidget(QWidget *parent = nullptr);

signals:

public slots:
protected:
    void timerEvent(QTimerEvent *event);
private:
    void initScene();
    void initChart1View();
    void initChart2View();
    void initLayout();
    void dataReceived(int value);
    int timerId; //��ʱ��
    int minX;
    int maxX;
    int maxY;
//    QList<double> data; // �洢ҵ�����ݵ� list
    QList<QPointF> data;
    QChart *chart1;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QChartView *chartView1;
    QSplineSeries *splineSeries;
    QScatterSeries *scatterSeries;

    QChart *chart2;
    QBarCategoryAxis *axisX2;
    QValueAxis *axisY2;
    QChartView *chartView2;
    QStackedBarSeries *stackedBarSeries;
    QBarSet *barSet;
    int xmin, xMax;
    int controlVal;
    QStringList m_barXlist;

    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // REALTIMECURVEQCHARTWIDGET_H
