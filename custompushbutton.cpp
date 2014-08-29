#include "custompushbutton.h"

CustomPushButton::CustomPushButton(QWidget *parent) :
    QPushButton(parent)
{
}

void CustomPushButton::enterEvent( QEvent* e )
{
    emit hoverStarted();
    QWidget::enterEvent( e );
}

void CustomPushButton::leaveEvent( QEvent* e )
{
    emit hoverEnded();
    QWidget::leaveEvent( e );
}
