#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QIcon>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
extern QString path;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap(":/res/1.png");
    QIcon ButtonIcon(pixmap);
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(ui->pushButton->size()*0.9);
    connect(ui->pushButton,SIGNAL(hoverStarted()),this,SLOT(IconPickBtnHoverStart()));
    connect(ui->pushButton,SIGNAL(hoverEnded()),this,SLOT(HoverEnd()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(IconPickBtnClick()));

    connect(ui->pushButton_2,SIGNAL(hoverStarted()),this,SLOT(CreateBtnHoverStart()));
    connect(ui->pushButton_2,SIGNAL(hoverEnded()),this,SLOT(HoverEnd()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(CreateBtnClick()));

    connect(ui->pushButton_3,SIGNAL(hoverStarted()),this,SLOT(CancelBtnHoverStart()));
    connect(ui->pushButton_3,SIGNAL(hoverEnded()),this,SLOT(HoverEnd()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(CancelBtnClick()));

    connect(ui->toolButton,SIGNAL(hoverStarted()),this,SLOT(ToolBtnHoverStart()));
    connect(ui->toolButton,SIGNAL(hoverEnded()),this,SLOT(HoverEnd()));
    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(ToolBtnClick()));

    connect(ui->lineEdit,SIGNAL(GotFocus()),this,SLOT(TitleEditFocus()));
    connect(ui->lineEdit,SIGNAL(LostFocus()),this,SLOT(HoverEnd()));

    connect(ui->lineEdit_2,SIGNAL(GotFocus()),this,SLOT(ExecEditFocus()));
    connect(ui->lineEdit_2,SIGNAL(LostFocus()),this,SLOT(HoverEnd()));

    connect(ui->lineEdit_3,SIGNAL(GotFocus()),this,SLOT(CommEditFocus()));
    connect(ui->lineEdit_3,SIGNAL(LostFocus()),this,SLOT(HoverEnd()));

    connect(ui->lineEdit_4,SIGNAL(GotFocus()),this,SLOT(CatEditFocus()));
    connect(ui->lineEdit_4,SIGNAL(LostFocus()),this,SLOT(HoverEnd()));
    if (path!="") ui->lineEdit_2->setText(path);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::IconPickBtnHoverStart()
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("Click to pick an icon.", 0);
}

void MainWindow::HoverEnd()
{
    ui->statusBar->clearMessage();
}

void MainWindow::IconPickBtnClick()
{
    QFileDialog fd;
    IconFile = fd.getOpenFileName(this,"Select Icon...","~/",tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    if(IconFile != "")
    {
        QPixmap pixmap(IconFile);
        QIcon ButtonIcon(pixmap);
        ui->pushButton->setIcon(ButtonIcon);
        ui->pushButton->setIconSize(ui->pushButton->size()*0.9);
        ui->statusBar->clearMessage();
        ui->statusBar->showMessage("Icon picked successfully.", 0);
    }
}

void MainWindow::CancelBtnHoverStart()
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("Click to exit.", 0);
}

void MainWindow::CancelBtnClick()
{
    QApplication::quit();
}

void MainWindow::CreateBtnHoverStart()
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("Click to create launcher.", 0);
}

void MainWindow::CreateBtnClick()
{
    Title = ui->lineEdit->text();
    ExecFile = ui->lineEdit_2->text();
    Comment = ui->lineEdit_3->text();
    Categories = ui->lineEdit_4->text();
    QString filename = Title.simplified();
    filename = filename.toLower();
    filename.replace(" ","");
    filename.append(".desktop");
   // QString fil1 = filename;
    //filename.prepend("~/");
    QFile file(filename);
    QString comm = "touch ";
    comm.append(filename);
    system(comm.toStdString().c_str());
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox msgBox;
        QString errmess = "Error creating file. Filename: ";
        errmess.append(filename);
        msgBox.setText(errmess);
        msgBox.exec();
        return;
    }
    QTextStream out(&file);
    out << "[Desktop Entry]\n";
    out << "Name=";
    if (Title=="")
    {
        QMessageBox msgBox;
        msgBox.setText("The \"Title\" field is required.");
        msgBox.exec();
        return;
    }
    out << Title << "\n";
    if (Comment!="") out << "Comment=" << Comment << "\n";
    out << "Exec=";
    if (ExecFile=="")
    {
        QMessageBox msgBox;
        msgBox.setText("The \"Executable\" field is required.");
        msgBox.exec();
        return;
    }
    out << ExecFile << "\n";
    if (IconFile!="") out << "Icon=" << IconFile << "\n";
    out << "Terminal=false\nType=Application\n";
    if (Categories!="") out << "Categories=" << Categories << "\n";
    file.close();
    QString command = "pkexec cp ";
    command.append(QDir::currentPath());
    command.append("/");
    command.append(filename);
    command.append(" /usr/share/applications/");
    system(command.toStdString().c_str());
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("The launcher has been created successfully.", 0);
    QMessageBox msgBox;
    msgBox.setText("The launcher has been created successfully.");
    msgBox.exec();
}

void MainWindow::ToolBtnHoverStart()
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("Click to pick the executable.", 0);
}

void MainWindow::ToolBtnClick()
{
    QFileDialog fd;
    ExecFile = fd.getOpenFileName(this,"Select Executable...","~/",tr("Executable Files (*)"));
    if(ExecFile != "")
    {
        ui->lineEdit_2->setText(ExecFile);
        ui->statusBar->clearMessage();
        ui->statusBar->showMessage("Executable picked successfully.", 0);
    }
}

void MainWindow::TitleEditFocus()
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("Input the launcher title here.", 0);
}

void MainWindow::ExecEditFocus()
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("Input the executable file path here. If it's a script, add \"sh \" before the path.", 0);
}

void MainWindow::CommEditFocus()
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("Input the description here - optional.", 0);
}

void MainWindow::CatEditFocus()
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("Input categories (put a semicolon after each tag) - optional.", 0);
}
