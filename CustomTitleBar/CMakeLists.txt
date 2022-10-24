set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# SET(CMAKE_PREFIX_PATH "D:/Qt/6.2.1/mingw81_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(CustomTitleBar ../resources.qrc widgets/buttons/CustomButton.h
        widgets/other/TitleBarProperties.h widgets/other/WindowEffect.cpp
        widgets/other/WindowEffect.h widgets/windowClasses/FramelessWindow.cpp
        widgets/windowClasses/FramelessWindow.h widgets/titleBars/TitleBar.h
        widgets/titleBars/TitleBar.cpp widgets/titleBars/SimpleTitleBar.cpp
        widgets/titleBars/SimpleTitleBar.h widgets/windows/CustomWindow.cpp
        widgets/windows/CustomWindow.h widgets/titleBars/DarkLightTitleBar.cpp
        widgets/titleBars/DarkLightTitleBar.h widgets/windows/DarkLightWindow.cpp
        widgets/windows/DarkLightWindow.h)

target_link_libraries(CustomTitleBar
        Qt::Core
        Qt::Gui
        Qt::Widgets
        dwmapi.lib # important!
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        #        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET CustomTitleBar POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:CustomTitleBar>/plugins/platforms/")
        add_custom_command(TARGET CustomTitleBar POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:CustomTitleBar>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET CustomTitleBar POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:CustomTitleBar>")
    endforeach (QT_LIB)
endif ()