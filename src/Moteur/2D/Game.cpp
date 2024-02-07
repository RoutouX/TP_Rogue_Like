//
// Created by thoma on 14/01/2024.
//

#include "Game.h"

#include "Physique/Composent/Composent.h"

class Engine;


Game::Game(bool* pShutdown, Window* pWindow, Engine* pEngine) :pShutdown(pShutdown) {
    this->pWindow = pWindow;
    this->pEngine = pEngine;
}

Game::~Game() {

}


void Game::initGame() {
    this->pMap = new Map(pShutdown);
    this->pCamera = new Camera(192000, 108000, 0, 0, this->pShutdown);
    Composent* composent1 = new Composent(this->pShutdown, 5000, 0, 0, true);
    composent1->setPMap(pMap);
    composent1->setVelocityX(9);
    composent1->setVelocityY(11);
    composent1->start();

    Composent* composent2 = new Composent(this->pShutdown, 3000, 40000, 40000, true);
    composent1->setPMap(pMap);
    composent1->start();

    this->pMap->addComposent(composent1);
    this->pMap->addComposent(composent2);
    pCamera->setPMap(this->pMap);
}



Camera *Game::getPCamera() const {
    return pCamera;
}


