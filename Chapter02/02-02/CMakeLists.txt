cmake_minimum_required( VERSION 3.23 )

project( Chapter02-02
    VERSION 1.0
    DESCRIPTION "A c++ Qt6 sample program"
    LANGUAGES CXX
)

# set( CMAKE_CXX_STANDARD 17 )

add_executable( Chapter02-02 )
target_sources( Chapter02-02 
    PRIVATE ./GotoCellDialog.h
    PRIVATE ./GotoCellDialog.cpp
    PRIVATE ./GotoCellDialog.ui
    PRIVATE ./main.cpp 
)
target_link_libraries( Chapter02-02 
    PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets
)

