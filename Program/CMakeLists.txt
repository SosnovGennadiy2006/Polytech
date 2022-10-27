set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# SET(CMAKE_PREFIX_PATH "D:/Qt/6.2.1/mingw81_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Program main.cpp ../resources.qrc widgets/other/StyleSheetsHelper.h
        widgets/other/Image.cpp widgets/other/Image.h widgets/windows/MainWindow.h
        widgets/windows/MainWindow.cpp widgets/containers/Workspace.cpp widgets/containers/Workspace.h
        widgets/buttons/StyledButton.cpp widgets/buttons/StyledButton.h widgets/containers/WelcomeContainer.cpp 
        widgets/containers/WelcomeContainer.h widgets/containers/WorkArea.cpp widgets/containers/WorkArea.h)

target_link_libraries(Program
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
        add_custom_command(TARGET Program POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:Program>/plugins/platforms/")
        add_custom_command(TARGET Program POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:Program>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET Program POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:Program>")
    endforeach (QT_LIB)
endif ()

include_directories(../CustomTitleBar)
target_link_libraries(Program CustomTitleBar)