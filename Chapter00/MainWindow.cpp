#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QStringListModel>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui( new Ui::MainWindow )
{
    // Set the size of the window
    //this->setWindowTitle("Hello, 메인 윈도우 World!");
    //setFixedSize(800, 600);

    ui->setupUi( this );

    QStringListModel* model = new QStringListModel( this );
    QStringList list;
    list << "Item 1" << "Item 2" << "Item 3" << "Item 4";
    model->setStringList( list );
    ui->listView->setModel( model );
}

MainWindow::~MainWindow()
{
    // nothing
}