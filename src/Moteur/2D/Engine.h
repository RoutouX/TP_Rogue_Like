//
// Created by thoma on 17/01/2024.
//

#ifndef TP_ROGUE_LIKE_ENGINE_H
#define TP_ROGUE_LIKE_ENGINE_H

#include "../Window/Window.h"
#include "Game.h"

class Engine {
public:
    Engine(bool* pShutdown);

    void init();
    void startGame();
    void onGameEnd();

private:
    bool* pShutdown;
    Window* pWindow = nullptr;
    Game* pGame = nullptr;
};


#endif //TP_ROGUE_LIKE_ENGINE_H
