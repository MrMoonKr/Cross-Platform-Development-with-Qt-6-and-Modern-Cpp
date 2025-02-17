#include <iostream>
#include <QApplication>
#include <QPushButton>

// int main( int argc, char* argv[] )
// {
//     std::cout << "Hello, World!" << std::endl;

//     QApplication app( argc, argv );

//     QPushButton button( "Hello,안녕하세요 World!" );
//     button.show();

//     return app.exec();

//     //return 0;
// }

#include "MainWindow.h"

int main( int argc, char* argv[] )
{
    std::cout << "Hello, World!" << std::endl;

    QApplication app( argc, argv );

    MainWindow window;
    window.show();

    return app.exec();

    //return 0;
}