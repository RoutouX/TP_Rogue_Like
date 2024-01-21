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
    Composent* composentTet = new Composent(this->pShutdown, 5000, 0, 0, true);
    composentTet->setVelocityX(5);
    composentTet->setVelocityY(11);
    composentTet->start();
    this->pMap->addComposent(composentTet);
    this->pMap->addComposent(new Composent(this->pShutdown, 3000, 40000, 40000, true));
    pCamera->setPMap(this->pMap);
}



Camera *Game::getPCamera() const {
    return pCamera;
}


