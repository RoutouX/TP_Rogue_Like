//
// Created by thoma on 14/01/2024.
//

#include <valarray>
#include "Camera.h"
#include "vector"
#include "../Physique/Composent/Composent.h"

Camera::Camera(long double width, long double height, long double x, long double y, bool *pShutdown)
        : SquareHitBox2D(width, height, x, y), pShutdown(pShutdown) {}

Map* Camera::getPMap() const {
    return pMap;
}

void Camera::setPMap(Map* pMap) {
    Camera::pMap = pMap;
}

std::vector<Composent*> Camera::getComposentToDraw() {
    std::vector<Composent*> listComposent = pMap->getComposentList();
    std::vector<Composent*> composentToDraw;
    for (int i = 0; i < size(listComposent); ++i) {
        if(SquareHitBox2D::itHit(listComposent[i])){
            composentToDraw.push_back(listComposent[i]);
        }
    }
    return composentToDraw;
}
