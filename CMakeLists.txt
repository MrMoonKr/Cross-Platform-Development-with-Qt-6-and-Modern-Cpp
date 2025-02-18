cmake_minimum_required( VERSION 3.23 )

# vcpkg 관련 설정

set( VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "" )
set( CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" )

#  Qt6 관련 설정

set( CMAKE_AUTOUIC ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )

# 최상위 프로젝트 설정

project( Cross-Platform-Development-with-Cpp-Qt6-and-Modern-Cpp 
    VERSION 1.0
    DESCRIPTION "The 'Build-All' in Instructions for All Chapters"
    LANGUAGES CXX
)

set( CMAKE_CXX_STANDARD 17 )

# 의존 패키지 찾기

# find_package( fmt CONFIG REQUIRED )
find_package( Qt6 COMPONENTS Core Gui Widgets REQUIRED )
# find_package( httplib CONFIG REQUIRED )
# find_package( CURL REQUIRED )
# find_package( nlohmann_json CONFIG REQUIRED )
# find_package( glfw3 CONFIG REQUIRED )
# find_package( imgui CONFIG REQUIRED )
# find_package( Stb REQUIRED )

# add_executable( HelloQt6 )
# target_sources( HelloQt6 
#     # PRIVATE ./src/DataManager.h
#     # PRIVATE ./src/DataManager.cpp
#     # PRIVATE ./src/GuiManager.h
#     # PRIVATE ./src/GuiManager.cpp
#     PRIVATE ./Chapter00/MainWindow.h
#     PRIVATE ./Chapter00/MainWindow.cpp
#     PRIVATE ./Chapter00/MainWindow.ui
#     PRIVATE ./Chapter00/main.cpp 
# )

# target_link_libraries( HelloQt6 
#     # PRIVATE fmt::fmt
#     PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets
#     # PRIVATE httplib::httplib
#     # PRIVATE CURL::libcurl
#     # PRIVATE nlohmann_json nlohmann_json::nlohmann_json
#     # PRIVATE glfw
#     # PRIVATE opengl32
#     # PRIVATE imgui::imgui
# )

# 실행에 필요한 파일 복사

# file( COPY ./data DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} )

file ( COPY ${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}/Qt6/plugins/
    DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ )

# 하위 프로젝트 추가

add_subdirectory( Chapter00 )
add_subdirectory( Chapter01 )
add_subdirectory( Chapter02 )

