#include <QApplication>

#include "GotoCellDialog.h"


int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    GotoCellDialog* dialog = new GotoCellDialog;
    dialog->show();

    return app.exec();
}
