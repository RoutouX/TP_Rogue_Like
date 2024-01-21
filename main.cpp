#include <iostream>

#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <unistd.h>


#include "src/Utility/Config.h"
#include "src/Moteur/Window/Window.h"

#include "src/Moteur/2D/Physique/Composent/SquareHitBox2D.h"
#include "src/Moteur/2D/Utility/Position2D.h"

#include "src/Moteur/2D/Physique/Composent/RoundHitBox2D.h"
#include "src/Moteur/2D/Physique/Composent/SquareHitBox2D.h"

#include "src/Moteur/2D/Physique/Composent/Composent.h"

#include "src/Moteur/2D/Engine.h"

int main() {
    /*
    bool windowsOff = false;
    Window* pWindow = new Window(&windowsOff);
    pWindow->start();
    while (!windowsOff);
     */

    /*
    bool shutdown = false;
    bool pause = false;
    Composent* pComposent = new Composent(&shutdown, 2, 0, 0, false);
    pComposent->setVelocityX(10);
    pComposent->setVelocityY(1);
    pComposent->start();
    while (!shutdown){
        std::cout << "X:"<< pComposent->getX() << " Y:" << pComposent->getY() << std::endl;
    }
    */

    bool shutdown = false;

    Engine* engine = new Engine(&shutdown);
    engine->init();
    engine->startGame();
    while (!shutdown){}

    std::cout << "End" << std::endl;

    return 0;
}
