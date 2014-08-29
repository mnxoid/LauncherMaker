#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QLineEdit>

class CustomLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit CustomLineEdit(QWidget *parent = 0);
protected:
    virtual void focusInEvent( QFocusEvent* e );
    virtual void focusOutEvent( QFocusEvent* e );
signals:
    void GotFocus();
    void LostFocus();
public slots:

};

#endif // CUSTOMLINEEDIT_H
