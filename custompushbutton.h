#ifndef CUSTOMPUSHBUTTON_H
#define CUSTOMPUSHBUTTON_H

#include <QPushButton>

class CustomPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CustomPushButton(QWidget *parent = 0);
protected:
    virtual void enterEvent( QEvent* e );
    virtual void leaveEvent( QEvent* e );
signals:
    void hoverStarted();
    void hoverEnded();
public slots:

};

#endif // CUSTOMPUSHBUTTON_H
