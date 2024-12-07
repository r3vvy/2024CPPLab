cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(TicTacToe src/main.cpp src/Board.cpp src/GameData.cpp src/Input.cpp)
target_link_libraries(TicTacToe sfml-graphics sfml-window sfml-system)

# Pentru teste
enable_testing()
add_executable(test_gamedata tests/test_gamedata.cpp src/GameData.cpp)
target_link_libraries(test_gamedata sfml-system sfml-window sfml-graphics)
add_test(NAME test_gamedata COMMAND test_gamedata)
