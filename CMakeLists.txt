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

# set warnings
target_compile_options(${PROJECT_NAME} PRIVATE 
    -Wall -pedantic 
    -pedantic-errors -Wextra -Wcast-align
    -Wchar-subscripts  -Wcomment
    -Wdisabled-optimization
    -Werror -Wfloat-equal  -Wformat  -Wformat=2
    -Wformat-nonliteral -Wformat-security 
    -Wformat-y2k
    -Wimport  -Winit-self  -Winline
    -Winvalid-pch  
    -Wunsafe-loop-optimizations  -Wlong-long
    -Wmissing-field-initializers -Wmissing-format-attribute  
    -Wmissing-noreturn
    -Wpacked -Wparentheses  -Wpointer-arith
    -Wredundant-decls -Wreturn-type
    -Wsequence-point -Wsign-compare  -Wstack-protector
    -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch -Wtrigraphs  -Wuninitialized
    -Wunknown-pragmas  -Wunreachable-code -Wunused
    -Wunused-function  -Wunused-label  -Wunused-parameter
    -Wunused-value  -Wunused-variable  -Wvariadic-macros
    -Wshadow
    -Wvolatile-register-var  -Wwrite-strings)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
)