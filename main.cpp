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

int main() {
    /*
    bool windowsOff = false;
    Window* pWindow = new Window(&windowsOff);
    pWindow->start();
    while (!windowsOff);
     */


    RoundHitBox2D* pRound = new RoundHitBox2D(1, 10,0);
    SquareHitBox2D* pSquare = new SquareHitBox2D(1,1, 0,0);


    std::cout << pRound->itHit(pSquare) << std::endl;


    return 0;
}
