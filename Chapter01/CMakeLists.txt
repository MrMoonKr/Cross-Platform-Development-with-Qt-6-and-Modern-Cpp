cmake_minimum_required( VERSION 3.23 )

project( Chapter01
    VERSION 1.0
    DESCRIPTION "A c++ Qt6 sample program"
    LANGUAGES CXX
)

# set( CMAKE_CXX_STANDARD 17 )

add_executable( Chapter01-01 )
target_sources( Chapter01-01 
    PRIVATE ./Chapter01-01.cpp 
)
target_link_libraries( Chapter01-01 
    PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets
)

add_executable( Chapter01-02 )
target_sources( Chapter01-02 
    PRIVATE ./Chapter01-02.cpp
)
target_link_libraries( Chapter01-02 
    PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets
)

add_executable( Chapter01-03 )
target_sources( Chapter01-03 
    PRIVATE ./Chapter01-03.cpp
)
target_link_libraries( Chapter01-03 
    PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets
)


