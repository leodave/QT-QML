cmake_minimum_required(VERSION 3.14)

project(TestingText LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing(true)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test PrintSupport)

add_executable(TestingText
  TestHandler.cpp
  ./../templatehandler.h
  ./../templatehandler.cpp

)
add_test(NAME Testing COMMAND Testing)
target_link_libraries(TestingText Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::PrintSupport)

#install(TARGETS TestingText
#   LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
