#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAbstractAnimation>

class QGraphicsOpacityEffect;
class QPropertyAnimation;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_demoButton_clicked();
    void on_animation_stateChanged(QAbstractAnimation::State newState,
                                   QAbstractAnimation::State oldState);

private:
    Ui::Widget *ui;
    QGraphicsOpacityEffect  *redOpacity;
    QPropertyAnimation      *redAnimation;
    int                     animationDuration;
};

#endif // WIDGET_H
