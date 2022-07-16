cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(qt_logger VERSION 1.0)

##### QT ######
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()
message(STATUS "QT library status:")
message(STATUS "    QT_VERSION: ${QT_VERSION}")


###### g3log #########
set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/g3log)
find_package(g3log CONFIG REQUIRED)
message(
"g3log package:
    found: ${G3LOG_FOUND}
    include dir: ${G3LOG_INCLUDE_DIRS}
    libraries: ${G3LOG_LIBRARIES}"
)
include_directories(${G3LOG_INCLUDE_DIRS})

###### main files ######
file (GLOB PROJECT_SOURCES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.ui
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} g3log Qt6::Widgets)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
