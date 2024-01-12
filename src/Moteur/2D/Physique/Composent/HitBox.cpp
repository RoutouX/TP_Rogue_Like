//
// Created by thoma on 11/01/2024.
//

#include "HitBox.h"

HitBox::HitBox(long double x, long double y) {
    Position2D(x, y);
}

HitBox::~HitBox(){}

bool HitBox::itHit(HitBox* pHitBox){
    return false;
}