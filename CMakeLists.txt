cmake_minimum_required(VERSION 3.10.2)
PROJECT( Doodle_Jump )

# The C++ standard version. Can be 98 11 14 or 17
set(CMAKE_CXX_STANDARD 17)
#set(SFML_INCLUDE_DIR "../../SFML-2.5.1/include")
#set(SFML_LIBRARY_DIR "../../SFML-2.5.1/build/lib")

#link_directories(${SFML_LIBRARY_DIR})
#include_directories(${SFML_INCLUDE_DIR})

#find_package(SFML 2.4 COMPONENTS system window graphics network audio)

#add_executable(Doodle_Jump main.cpp)
#target_link_libraries (Doodle_Jump sfml-graphics sfml-window sfml-system)
#target_link_libraries(Doodle_Jump sfml-graphics sfml-system sfml-system)


# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics audio network)

ADD_EXECUTABLE(Doodle_Jump
	src/main.cpp
		src/game_representation/Game.cpp
	src/game_representation/Game.h
	src/game_representation/ConcreteFactory.cpp
	src/game_representation/ConcreteFactory.h
	src/game_representation/EntityView.cpp
	src/game_representation/EntityView.h
	src/game_representation/Player.cpp
	src/game_representation/Player.h
	src/game_representation/Platform.cpp
	src/game_representation/Platform.h
	src/game_representation/BGTile.cpp
	src/game_representation/BGTile.h
	src/game_representation/Bonus.cpp
	src/game_representation/Bonus.h
	src/game_representation/Data.cpp
	src/game_representation/Data.h
	src/game_representation/Horizontal.cpp
	src/game_representation/Horizontal.h
	src/game_representation/Jetpack.cpp
	src/game_representation/Jetpack.h
	src/game_representation/Spring.cpp
	src/game_representation/Spring.h
	src/game_representation/Static.cpp
	src/game_representation/Static.h
	src/game_representation/Temporary.cpp
	src/game_representation/Temporary.h
	src/game_representation/Vertical.cpp
	src/game_representation/Vertical.h
	src/game_representation/Score.h
	src/game_representation/Score.cpp
	src/game_representation/Spike.h
	src/game_representation/Spike.cpp
	src/game_representation/HP.h
	src/game_representation/HP.cpp
	src/game_representation/VerticalTeleport.h
	src/game_representation/VerticalTeleport.cpp
	src/game_representation/HorizontalTeleport.h
	src/game_representation/HorizontalTeleport.cpp
	src/game_representation/SimpleEnemy.h
	src/game_representation/SimpleEnemy.cpp
	src/game_representation/ComplexEnemy.h
	src/game_representation/ComplexEnemy.cpp)

ADD_LIBRARY(GameLogic STATIC
	src/logic_library/Stopwatch.cpp
	src/logic_library/Stopwatch.h
	src/logic_library/World.cpp
	src/logic_library/World.h
	src/logic_library/Camera.cpp
	src/logic_library/Camera.h
	src/logic_library/Random.cpp
	src/logic_library/Random.h
	src/logic_library/SimpleEnemy.h
	src/logic_library/SimpleEnemy.cpp
	src/logic_library/ComplexEnemy.h
	src/logic_library/ComplexEnemy.cpp
	src/logic_library/Spike.h
	src/logic_library/Spike.cpp
	src/logic_library/HP.h
	src/logic_library/HP.cpp
	src/logic_library/VerticalTeleport.h
	src/logic_library/VerticalTeleport.cpp
	src/logic_library/HorizontalTeleport.h
	src/logic_library/HorizontalTeleport.cpp
	src/logic_library/Observer.cpp
	src/logic_library/Observer.h
	src/logic_library/Score.cpp
	src/logic_library/Score.h
	src/logic_library/EntityModel.cpp
	src/logic_library/EntityModel.h
	src/logic_library/Subject.cpp
	src/logic_library/Subject.h
	src/logic_library/Player.cpp
	src/logic_library/Player.h
	src/logic_library/Platform.cpp
	src/logic_library/Platform.h
	src/logic_library/BGTile.cpp
	src/logic_library/BGTile.h
	src/logic_library/Bonus.cpp
	src/logic_library/Bonus.h
	src/logic_library/AbstractFactory.cpp
	src/logic_library/AbstractFactory.h
	src/logic_library/Vertical.cpp
	src/logic_library/Vertical.h
	src/logic_library/Temporary.cpp
	src/logic_library/Temporary.h
	src/logic_library/Static.cpp
	src/logic_library/Static.h
	src/logic_library/Spring.cpp
	src/logic_library/Spring.h
	src/logic_library/Jetpack.cpp
	src/logic_library/Jetpack.h
	src/logic_library/INPUT.h
	src/logic_library/Horizontal.cpp
	src/logic_library/Horizontal.h src/logic_library/EVENT.h src/logic_library/CONSTANTS.h src/logic_library/CONSTANTS.cpp src/logic_library/Doodle.cpp src/logic_library/Doodle.h)

TARGET_LINK_LIBRARIES(Doodle_Jump GameLogic)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
#ADD_EXECUTABLE(Doodle_Jump ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(Doodle_Jump ${SFML_LIBRARIES})

INSTALL(TARGETS Doodle_Jump DESTINATION ${PROJECT_SOURCE_DIR}/bin)
