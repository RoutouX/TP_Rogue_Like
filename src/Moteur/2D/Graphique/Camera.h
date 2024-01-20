//
// Created by thoma on 14/01/2024.
//

#ifndef TP_ROGUE_LIKE_CAMERA_H
#define TP_ROGUE_LIKE_CAMERA_H

#include "../Physique/Composent/SquareHitBox2D.h"
#include "../Physique/Map.h"

class Camera : public SquareHitBox2D{
public:
    Camera(long double width, long double height, long double x, long double y, bool *pShutdown);

    std::vector<Composent*> getComposentToDraw();

    Map *getPMap() const;

    void setPMap(Map *pMap);

private:
    bool* pShutdown = nullptr;
    Map* pMap = nullptr;
};


#endif //TP_ROGUE_LIKE_CAMERA_H
