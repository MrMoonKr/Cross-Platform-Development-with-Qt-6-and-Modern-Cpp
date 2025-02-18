cmake_minimum_required( VERSION 3.23 )

project( Chapter02-03
    VERSION 1.0
    DESCRIPTION "A c++ Qt6 sample program"
    LANGUAGES CXX
)

# set( CMAKE_CXX_STANDARD 17 )

add_executable( Chapter02-03 )
target_sources( Chapter02-03 
    PRIVATE ./SortDialog.h
    PRIVATE ./SortDialog.cpp
    PRIVATE ./SortDialog.ui
    PRIVATE ./main.cpp 
)
target_link_libraries( Chapter02-03 
    PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets
)

