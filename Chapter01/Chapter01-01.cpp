#include <QApplication>
#include <QLabel>

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );
    QLabel myLabel;
    myLabel.setText( "Chapter01-01. Hello World! 안녕하세요 !!!" );
    myLabel.show();
    return app.exec();
}