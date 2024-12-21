cmake_minimum_required(VERSION 3.5)

project(towing_project LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

# if(ANDROID)
# set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
# if (ANDROID_ABI STREQUAL "armeabi-v7a")
# set(ANDROID_EXTRA_LIBS
# ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
# ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
# endif()
# endif()
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# 查找 Eigen
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# 查找 GSL
find_package(GSL REQUIRED)

if(ANDROID)
  add_library(towing_project SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    environment_loads.h
    environment_loads.cpp
  )
else()
  add_executable(towing_project
    main.cpp mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    environment_loads.h
    environment_loads.cpp
  )
endif()

# 包含头文件
include_directories(
  ${EIGEN3_INCLUDE_DIR}
  ${GSL_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
)

target_link_libraries(towing_project PRIVATE Qt5::Widgets
  Eigen3::Eigen
  ${GSL_LIBRARIES}
)
