cmake_minimum_required(VERSION 3.16)

project(DineAutoProjectV3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        main.ui
        main.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DineAutoProjectV3
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        credentials.csv
        LoginScreenUI.h LoginScreenUI.cpp LoginScreenUI.ui
        MenuScreenUI.h MenuScreenUI.cpp MenuScreenUI.ui
        menu.csv
        Temp/creditCards.txt Temp/menu.cpp Temp/menu.csv Temp/menu.hpp Temp/menuItem.cpp Temp/menuItem.hpp Temp/orderDataBase.cpp Temp/orderDataBase.hpp Temp/orders.csv Temp/shoppingCart.cpp Temp/shoppingCart.hpp
        CartDialog.h CartDialog.cpp CartDialog.ui
        CheckoutDialog.h CheckoutDialog.cpp CheckoutDialog.ui
        AdminScreenUI.h AdminScreenUI.cpp AdminScreenUI.ui
        Temp/queue.cpp Temp/queue.hpp





    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET DineAutoProjectV3 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(DineAutoProjectV3 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(DineAutoProjectV3
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Define the source and destination paths for credentials.csv
set(CREDENTIALS_CSV_SOURCE "${CMAKE_SOURCE_DIR}/credentials.csv")
set(CREDENTIALS_CSV_DESTINATION "${CMAKE_BINARY_DIR}")

# Add a custom command to copy credentials.csv to the binary directory
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CREDENTIALS_CSV_SOURCE}" "${CREDENTIALS_CSV_DESTINATION}"
)

# Define the source and destination paths for menu.csv
set(MENU_CSV_SOURCE "${CMAKE_SOURCE_DIR}/menu.csv")
set(MENU_CSV_DESTINATION "${CMAKE_BINARY_DIR}")

# Add a custom command to copy menu.csv to the binary directory
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${MENU_CSV_SOURCE}" "${MENU_CSV_DESTINATION}"
)

# Define the source and destination paths for creditCards.txt
set(CREDIT_CARDS_SOURCE "${CMAKE_SOURCE_DIR}/Temp/creditCards.txt")
set(CREDIT_CARDS_DESTINATION "${CMAKE_BINARY_DIR}")

# Add a custom command to copy creditCards.txt to the binary directory
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CREDIT_CARDS_SOURCE}" "${CREDIT_CARDS_DESTINATION}"
)

#set(ORDERS_CSV_SOURCE "${CMAKE_SOURCE_DIR}/Temp/orders.csv")
#set(ORDERS_CSV_DESTINATION "${CMAKE_BINARY_DIR}/orders.csv")
#add_custom_command(
#    TARGET ${PROJECT_NAME} POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different
#    ${ORDERS_CSV_SOURCE} ${ORDERS_CSV_DESTINATION}
#)

# Define the source and destination paths for orders.csv for copying back to Temp
set(ORDERS_BUILD_PATH "${CMAKE_BINARY_DIR}/orders.csv")
set(ORDERS_TEMP_PATH "${CMAKE_SOURCE_DIR}/Temp/orders.csv")

# Add a custom command to copy orders.csv back to Temp after the build
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${ORDERS_BUILD_PATH}" "${ORDERS_TEMP_PATH}"
)



target_link_libraries(DineAutoProjectV3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.DineAutoProjectV3)
endif()
set_target_properties(DineAutoProjectV3 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)



include(GNUInstallDirs)
install(TARGETS DineAutoProjectV3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DineAutoProjectV3)
endif()
