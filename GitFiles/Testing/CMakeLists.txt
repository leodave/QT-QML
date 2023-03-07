cmake_minimum_required(VERSION 3.14)

project(Testing LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing(true)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test)

add_executable(Testing
  TestQString.cpp
)
target_link_libraries(Testing Qt${QT_VERSION_MAJOR}::Core  Qt${QT_VERSION_MAJOR}::Test)

install(TARGETS Testing
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
