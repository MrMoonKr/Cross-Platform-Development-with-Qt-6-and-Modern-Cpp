cmake_minimum_required( VERSION 3.23 )

project( Chapter02-01
    VERSION 1.0
    DESCRIPTION "A c++ Qt6 sample program"
    LANGUAGES CXX
)

# set( CMAKE_CXX_STANDARD 17 )

add_executable( Chapter02-01 )
target_sources( Chapter02-01 
    PRIVATE ./FindDialog.h
    PRIVATE ./FindDialog.cpp
    PRIVATE ./main.cpp 
)
target_link_libraries( Chapter02-01 
    PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets
)

