cmake_minimum_required( VERSION 3.23 )

project( Chapter03-01
    VERSION 1.0
    DESCRIPTION "A c++ Qt6 sample program"
    LANGUAGES CXX
)

# set( CMAKE_CXX_STANDARD 17 )

qt_add_executable( Chapter03-01 WIN32
    Cell.h
    Cell.cpp
    FindDialog.h
    FindDialog.cpp
    GotoCellDialog.h
    GotoCellDialog.cpp
    GotoCellDialog.ui
    SortDialog.h
    SortDialog.cpp
    SortDialog.ui
    SpreadSheet.h
    SpreadSheet.cpp
    MainWindow.h
    MainWindow.cpp
    main.cpp 
)

target_link_libraries( Chapter03-01 
    PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets
)

