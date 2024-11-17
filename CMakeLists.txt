set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Set the project name
project(DineAutoProgram)

# Add an executable
add_executable(DineAutoProgram main.cpp orderDataBase.cpp menuItem.cpp shoppingCart.cpp menu.cpp analytics.cpp)