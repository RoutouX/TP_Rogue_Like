//
// Created by thoma on 14/01/2024.
//

#ifndef TP_ROGUE_LIKE_GAME_H
#define TP_ROGUE_LIKE_GAME_H

#include "../../Utility/Thread.h"
#include "Physique/Map.h"
#include "Graphique/Camera.h"
#include "../Window/Window.h"

class Engine;

class Game{
public:

    Game(bool* pShutdown, Window* pWindow, Engine* pEngine);
    virtual ~Game();


    Camera *getPCamera() const;

    void initGame();

private:

    bool* pShutdown = nullptr;


    Map* pMap = nullptr;
    Camera* pCamera = nullptr;
    Window* pWindow = nullptr;
    Engine* pEngine = nullptr;

};


#endif //TP_ROGUE_LIKE_GAME_H
