//
// Created by thoma on 11/01/2024.
//

#include "RoundHitBox2D.h"
#include "SquareHitBox2D.h"
#include <math.h>
#include <iostream>

RoundHitBox2D::RoundHitBox2D(long double rayon, long double x, long double y):HitBox(x, y){
    this->rayon = rayon;
}
RoundHitBox2D::~RoundHitBox2D(){}

bool RoundHitBox2D::itHit(HitBox* pHitBox){
    if (dynamic_cast<SquareHitBox2D*>(pHitBox) != nullptr) {
        long double circleDistanceX = abs(this->getX() - dynamic_cast<SquareHitBox2D*>(pHitBox)->getX() - dynamic_cast<SquareHitBox2D*>(pHitBox)->getWidth()/2);
        long double circleDistanceY = abs(this->getY() - dynamic_cast<SquareHitBox2D*>(pHitBox)->getY() - dynamic_cast<SquareHitBox2D*>(pHitBox)->getHeight()/2);
        if (circleDistanceX > (dynamic_cast<SquareHitBox2D*>(pHitBox)->getWidth() / 2 + this->getRayon())) { return false; }
        if (circleDistanceY > (dynamic_cast<SquareHitBox2D*>(pHitBox)->getHeight() / 2 +this->getRayon())) { return false; }
        if (circleDistanceX <= (dynamic_cast<SquareHitBox2D*>(pHitBox)->getWidth()/2)) { return true; }
        if (circleDistanceY <= (dynamic_cast<SquareHitBox2D*>(pHitBox)->getHeight()/2)) { return true; }
        long double cornerDistance_sq = pow((circleDistanceX - dynamic_cast<SquareHitBox2D*>(pHitBox)->getWidth()/2),2) + pow((circleDistanceY - dynamic_cast<SquareHitBox2D*>(pHitBox)->getHeight()/2),2);
        return (cornerDistance_sq <= pow(this->rayon,2));
    } else if (dynamic_cast<RoundHitBox2D*>(pHitBox) != nullptr){
        if (dynamic_cast<RoundHitBox2D*>(pHitBox)->getRayon() + this->rayon <= this->distanceAvec(pHitBox)){
            return true;
        } else {
            return false;
        }
    }
}

long double RoundHitBox2D::getRayon() const {
    return rayon;
}

void RoundHitBox2D::setRayon(long double rayon) {
    RoundHitBox2D::rayon = rayon;
}


