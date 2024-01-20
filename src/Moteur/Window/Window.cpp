//
// Created by thoma on 06/08/2023.
//


#include "Window.h"

#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include <iostream>
#include <vector>
#include <valarray>
#include <unistd.h>


Window::Window(bool* shutdown) {
    this->shutdown = shutdown;
}

Window::~Window(){
}


void Window::run(std::future<void> const& stop_token) {

    if (!glfwInit()) {
        std::cout << "glfwInit Fail" << std::endl;
        exit(0001);
    }
    this->monitor = glfwGetPrimaryMonitor();
    this->mode = glfwGetVideoMode(this->monitor);
    glfwWindowHint(GLFW_RED_BITS, this->mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, this->mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, this->mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, this->mode->refreshRate);
    this->window = glfwCreateWindow(mode->width, mode->height, "UnNamedGame", monitor, NULL);
    glfwSetWindowMonitor(this->window, this->monitor, 0, 0, this->mode->width, this->mode->height, this->mode->refreshRate);
    if (!this->window) {
        glfwTerminate();
        std::cout << "window create Fail" << std::endl;
        exit(0002);
    }
    glfwMakeContextCurrent(this->window);


    while (!is_stop_requested(stop_token) && !glfwWindowShouldClose(this->window) && !*this->shutdown) {
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            if (drawgame && pCamera != nullptr){
                glColor3f(0.0, 0.5, 0.5);
                drawComponentHitBoxWithCamera();

            }else{
                std::cout << "drawgame : " << drawgame << " pCamera : " << pCamera << std::endl;
            }

            glEnd();
            /**
            glBegin(GL_QUADS);
            glColor3f(1.0f, 0.0f, 0.0f); // Couleur rouge (RVB)
            glVertex2f(-0.5f, -0.5f); // Coin inférieur gauche
            glVertex2f(0.5f, -0.5f);  // Coin inférieur droit
            glVertex2f(0.5f, 0.5f);   // Coin supérieur droit
            glVertex2f(-0.5f, 0.5f);  // Coin supérieur gauche
            glEnd();
            */

            //EndLoop
            glfwSwapBuffers(this->window);
            glfwPollEvents();
            //usleep(delay1/60);
    }
    glfwTerminate();
    *this->shutdown = true;
}

void Window::setPCamera(Camera *pCamera) {
    Window::pCamera = pCamera;
}

void Window::setDrawgame(bool drawgame) {
    Window::drawgame = drawgame;
}

void Window::drawComponentHitBoxWithCamera() {
    std::vector<Composent *> listComposent = pCamera->getComposentToDraw();
    //std::cout << "size : " << size(listComposent) << std::endl;
    for (int i = 0; i < size(listComposent); ++i) {
        long double diffX = listComposent[i]->getX() - pCamera->getX();
        float posEcranX = diffX/pCamera->getWidth();
        long double diffY = listComposent[i]->getY() - pCamera->getY();
        float posEcranY = diffY/pCamera->getHeight();
        long double rayonScreen = listComposent[i]->getRayon() / pCamera->getHeight();
        std::cout << "posEcranX : " << posEcranX << " posEcranY : " << posEcranY << " rayonScreen : " << rayonScreen << std::endl;
        drawCircle(posEcranX, posEcranY, rayonScreen, 360);
    }
}

void Window::drawCircle(float cx, float cy, float r, int num_segments){
        glColor3f(0.0, 0.5, 0.5);
        float theta = 3.1415926 * 2 / float(num_segments);
        float tangetial_factor = tanf(theta);//calculate the tangential factor

        float radial_factor = cosf(theta);//calculate the radial factor

        float x = r;//we start at angle = 0

        float y = 0;
        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
        for (int ii = 0; ii < num_segments; ii++){
            glVertex2f(x + cx, y + cy);//output vertex

            //calculate the tangential vector
            //remember, the radial vector is (x, y)
            //to get the tangential vector we flip those coordinates and negate one of them

            float tx = -y;
            float ty = x;

            //add the tangential vector

            x += tx * tangetial_factor;
            y += ty * tangetial_factor;

            //correct using the radial factor

            x *= radial_factor;
            y *= radial_factor;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        glEnd();//was on comm
}







