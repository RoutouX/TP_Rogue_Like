cmake_minimum_required(VERSION 3.26)
project(TP_Rogue_Like)

set(CMAKE_CXX_STANDARD 17)

include_directories(glfw-3.3.8.bin.WIN64/include)
link_directories(glfw-3.3.8.bin.WIN64/lib-mingw-w64)
find_package(OpenGL REQUIRED)

add_executable(TP_Rogue_Like main.cpp src/Utility/Config.cpp src/Utility/Config.h src/Utility/fonnct/fonctAdaptOS.cpp src/Utility/fonnct/fonctAdaptOS.h src/Utility/fonnct/fonctManipulateString.cpp src/Utility/fonnct/fonctManipulateString.h src/Moteur/Window/Window.cpp src/Moteur/Window/Window.h src/Utility/Thread.cpp src/Utility/Thread.h src/Moteur/2D/Utility/Position2D.cpp src/Moteur/2D/Utility/Position2D.h src/Moteur/2D/Physique/Composent/Composent.cpp src/Moteur/2D/Physique/Composent/Composent.h src/Moteur/2D/Physique/Composent/SquareHitBox2D.cpp src/Moteur/2D/Physique/Composent/SquareHitBox2D.h src/Moteur/2D/Physique/Map.cpp src/Moteur/2D/Physique/Map.h
        src/Moteur/2D/Physique/Composent/RoundHitBox2D.cpp
        src/Moteur/2D/Physique/Composent/RoundHitBox2D.h
        src/Moteur/2D/Physique/Composent/HitBox.cpp
        src/Moteur/2D/Physique/Composent/HitBox.h
        src/Moteur/2D/Graphique/Camera.cpp
        src/Moteur/2D/Graphique/Camera.h
        src/Moteur/2D/Game.cpp
        src/Moteur/2D/Game.h
        src/Moteur/2D/Engine.cpp
        src/Moteur/2D/Engine.h)

target_link_libraries(TP_Rogue_Like glfw3 OpenGL::GL)
