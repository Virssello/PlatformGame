cmake_minimum_required(VERSION 3.20)
project(bawienie_sie_klockami)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 14)

add_executable(game main.cpp MapObject.cpp MapObject.h StateWrapper.cpp StateWrapper.h State.cpp State.h Game.cpp Game.h Menu.cpp Menu.h GameScreen.cpp GameScreen.h WinScreen.cpp WinScreen.h LoseScreen.cpp LoseScreen.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics audio network window system REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(game sfml-graphics sfml-audio sfml-network sfml-window sfml-system )