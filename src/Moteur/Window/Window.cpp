//
// Created by thoma on 06/08/2023.
//

#include "Window.h"

#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include <iostream>

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

            glBegin(GL_QUADS);
            glColor3f(1.0f, 0.0f, 0.0f); // Couleur rouge (RVB)
            glVertex2f(-0.5f, -0.5f); // Coin inférieur gauche
            glVertex2f(0.5f, -0.5f);  // Coin inférieur droit
            glVertex2f(0.5f, 0.5f);   // Coin supérieur droit
            glVertex2f(-0.5f, 0.5f);  // Coin supérieur gauche
            glEnd();


            //EndLoop
            glfwSwapBuffers(this->window);
            glfwPollEvents();
    }
    glfwTerminate();
    *this->shutdown = true;
}