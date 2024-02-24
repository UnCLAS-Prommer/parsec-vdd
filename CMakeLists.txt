cmake_minimum_required(VERSION 3.5)

project(VirtualDisplayGUI LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(outputdir ${CMAKE_CURRENT_SOURCE_DIR}/output)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${outputdir})
set(SETUPAPI_LIB_DIR "C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.22621.0\\um\\x64")
set(Qt5_DIR "Z:/Qt/Qt5.14.2/5.14.2/mingw73_64/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

add_executable(VirtualDisplayGUI
    WIN32
    virtual-display.cpp
    include/Main.h
    include/MainUI.h
    include/HMain.cpp
    include/parsec-vdd.h
    #parsec-vdd-demo.cc
)
target_link_libraries(VirtualDisplayGUI PRIVATE Qt5::Widgets Qt5::Core Setupapi)