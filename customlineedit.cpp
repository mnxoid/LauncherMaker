#include "customlineedit.h"

CustomLineEdit::CustomLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

void CustomLineEdit::focusInEvent( QFocusEvent* e )
{
    emit GotFocus();
    QWidget::focusInEvent( e );
}

void CustomLineEdit::focusOutEvent(QFocusEvent *e )
{
    emit LostFocus();
    QWidget::focusOutEvent( e );
}
