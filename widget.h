#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QCloseEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public:
    enum Order {
        Ascending,
        Descending
    };
    void OpacityWindow(Order order, QWidget *target); //���ڽ���
    void DropWindow(QWidget *target); //������׹
    void CloseWindow(); //�����ıպ�
    void ExpandWindow(int width, int height, QWidget *target); //������չ��
    void ShakeWindow();
public slots:
    void On_PushButton_expand_Pressed();
protected:
    void closeEvent(QCloseEvent *event);
private:
    QPushButton *PushButton_expand;
    void initUI();
};

#endif // WIDGET_H
