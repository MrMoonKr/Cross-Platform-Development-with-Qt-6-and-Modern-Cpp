#include <QApplication>

#include "MainWindow.h"

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    MainWindow mainFrame;
    mainFrame.show();

    return app.exec();
}