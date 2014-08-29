#include "customtoolbutton.h"

CustomToolButton::CustomToolButton(QWidget *parent) :
    QToolButton(parent)
{
}

void CustomToolButton::enterEvent( QEvent* e )
{
    emit hoverStarted();
    QWidget::enterEvent( e );
}

void CustomToolButton::leaveEvent( QEvent* e )
{
    emit hoverEnded();
    QWidget::leaveEvent( e );
}
