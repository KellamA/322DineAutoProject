cmake_minimum_required(VERSION 3.1)

# Set the project name
project(DineAutoProgram)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Optional: Enforce strict ISO compliance

# Add an executable
add_executable(DineAutoProgram
    main.cpp
    orderDataBase.cpp
    menuItem.cpp
    shoppingCart.cpp
    menu.cpp
    analytics.cpp
    queue.cpp
)
