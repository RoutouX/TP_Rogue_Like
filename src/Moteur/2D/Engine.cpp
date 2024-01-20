//
// Created by thoma on 17/01/2024.
//

#include "Engine.h"

class Game;

Engine::Engine(bool* pShutdown) {
    this->pShutdown = pShutdown;
}

void Engine::init() {
    this->pWindow = new Window(pShutdown);
    this->pGame = new Game(pShutdown, pWindow, this);
}

void Engine::startGame() {
    pWindow->start();
    pGame->initGame();
    //std::cout << "camera = " << pGame->getPCamera() << std::endl;
    pWindow->setPCamera(pGame->getPCamera());
    pWindow->setDrawgame(true);
}

void Engine::onGameEnd() {

}

