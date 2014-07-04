#include "widget.h"
#include "ui_widget.h"

#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    redOpacity(nullptr),
    animationDuration(1000)
{
    ui->setupUi(this);

    redOpacity = new QGraphicsOpacityEffect(ui->redWidget);
    ui->redWidget->setGraphicsEffect(redOpacity);
    redOpacity->setOpacity(1);

    redAnimation = new QPropertyAnimation(redOpacity, "opacity", this);
    redAnimation->setStartValue(1);
    redAnimation->setEndValue(0);
    redAnimation->setDuration(animationDuration);
    redAnimation->setEasingCurve(QEasingCurve::Linear);

    connect(redAnimation, SIGNAL(stateChanged(QAbstractAnimation::State,QAbstractAnimation::State)),
            this, SLOT(on_animation_stateChanged(QAbstractAnimation::State,QAbstractAnimation::State))
            );
}

Widget::~Widget() {
    delete ui;
}

void Widget::on_demoButton_clicked() {

    if (redAnimation->state() != QAbstractAnimation::Stopped) {
        redAnimation->pause();
    }

    redAnimation->start();
}

void Widget::on_animation_stateChanged(QAbstractAnimation::State newState,
                                       QAbstractAnimation::State oldState) {

    if (newState != QAbstractAnimation::Running) {
        if (redAnimation->direction() == QAbstractAnimation::Forward) {
            redAnimation->setDirection(QAbstractAnimation::Backward);
        } else {
            redAnimation->setDirection(QAbstractAnimation::Forward);
        }
    }

}
