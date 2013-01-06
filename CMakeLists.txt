project(PlACloud)
cmake_minimum_required(VERSION 2.8)
find_package(Qt4 REQUIRED)
find_package(KDE4 REQUIRED)

include_directories(${QT_INCLUDES})
include_directories(${KDE4_INCLUDES})

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

set(PlACloud_UI
gui/PlACloud.ui
)

set ( PlACloud_HEADERS
gui/PlACloud.h
src/application.h
src/kConfigOwnCloud.h
)

set(PlACLoud_SRCS
commons.h
src/application.cpp
src/configurator.cpp
src/fileOwnCloud.cpp
src/kConfigOwnCloud.cpp
gui/PlACloud.cpp
)

qt4_wrap_cpp(PlACloud_HEADERS_MOC ${PlACloud_HEADERS})
qt4_wrap_ui(PlACloud_UI_SRCS ${PlACloud_UI})
qt4_automoc(${PlACloud_SRCS})

#add_library(PlACloud_static STATIC ${PlACLoud_SRCS} ${PlACloud_UI_SRCS})
#target_link_libraries(PlACloud_static ${QT_LIBRARIES})

add_executable(PlACloud main.cpp ${PlACLoud_SRCS} ${PlACloud_HEADERS_MOC} ${PlACloud_UI_SRCS})
target_link_libraries(PlACloud ${QT_LIBRARIES} ${KDE4_KPARTS_LIBS})
#target_link_libraries(PlACLoud PlACloud_static)

####
#add_executable(PlACloud ${PlACloud_SRCS})
#target_link_libraries(PlACloud ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})