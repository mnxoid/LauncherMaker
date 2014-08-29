#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString IconFile;
    QString Title;
    QString ExecFile;
    QString Comment;
    QString Categories;
private slots:
    void IconPickBtnHoverStart();
    void HoverEnd();
    void IconPickBtnClick();
    void CancelBtnHoverStart();
    void CancelBtnClick();
    void CreateBtnHoverStart();
    void CreateBtnClick();
    void ToolBtnHoverStart();
    void ToolBtnClick();
    void TitleEditFocus();
    void ExecEditFocus();
    void CommEditFocus();
    void CatEditFocus();
};

#endif // MAINWINDOW_H
