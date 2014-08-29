#ifndef CUSTOMTOOLBUTTON_H
#define CUSTOMTOOLBUTTON_H

#include <QToolButton>

class CustomToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit CustomToolButton(QWidget *parent = 0);
protected:
    virtual void enterEvent( QEvent* e );
    virtual void leaveEvent( QEvent* e );
signals:
    void hoverStarted();
    void hoverEnded();
public slots:

};

#endif // CUSTOMTOOLBUTTON_H
