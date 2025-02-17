cmake_minimum_required( VERSION 3.23 )

# set( VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "" )
# set( CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" )

# set( CMAKE_AUTOUIC ON )
# set( CMAKE_AUTOMOC ON )
# set( CMAKE_AUTORCC ON )


project( Chapter00 
    VERSION 1.0
    DESCRIPTION "A c++ Qt6 sample program"
    LANGUAGES CXX
)

# set( CMAKE_CXX_STANDARD 17 )

# find_package( fmt CONFIG REQUIRED )
# find_package( Qt6 COMPONENTS Core Gui Widgets REQUIRED )
# find_package( httplib CONFIG REQUIRED )
# find_package( CURL REQUIRED )
# find_package( nlohmann_json CONFIG REQUIRED )
# find_package( glfw3 CONFIG REQUIRED )
# find_package( imgui CONFIG REQUIRED )
# find_package( Stb REQUIRED )

add_executable( Chapter00 )
target_sources( Chapter00 
    # PRIVATE ./src/DataManager.h
    # PRIVATE ./src/DataManager.cpp
    # PRIVATE ./src/GuiManager.h
    # PRIVATE ./src/GuiManager.cpp
    PRIVATE ./MainWindow.h
    PRIVATE ./MainWindow.cpp
    PRIVATE ./MainWindow.ui
    PRIVATE ./main.cpp 
)

target_link_libraries( Chapter00 
    # PRIVATE fmt::fmt
    PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets
    # PRIVATE httplib::httplib
    # PRIVATE CURL::libcurl
    # PRIVATE nlohmann_json nlohmann_json::nlohmann_json
    # PRIVATE glfw
    # PRIVATE opengl32
    # PRIVATE imgui::imgui
)

# file( COPY ./data DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} )

