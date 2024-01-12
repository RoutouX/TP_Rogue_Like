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
        std::cout << "Its a Square" << std::endl;
        long double circleDistanceX = distanceXAvec(pHitBox);
        long double circleDistanceY = distanceYAvec(pHitBox);
        if (circleDistanceX > (dynamic_cast<SquareHitBox2D*>(pHitBox)->getWidth()/2 + this->rayon)) { return false; }
        std::cout << "Toujours pas" << std::endl;
        if (circleDistanceY > (dynamic_cast<SquareHitBox2D*>(pHitBox)->getHeight()/2 + this->rayon)) { return false; }
        std::cout << "Toujours pas" << std::endl;
        if (circleDistanceX <= (dynamic_cast<SquareHitBox2D*>(pHitBox)->getWidth()/2)) { return true; }
        std::cout << "Toujours pas" << std::endl;
        if (circleDistanceY <= (dynamic_cast<SquareHitBox2D*>(pHitBox)->getHeight()/2)) { return true; }
        std::cout << "Toujours pas" << std::endl;
        double cornerDistance_sq = pow(circleDistanceX - dynamic_cast<SquareHitBox2D*>(pHitBox)->getWidth()/2,2) + pow(circleDistanceY - dynamic_cast<SquareHitBox2D*>(pHitBox)->getHeight()/2, 2);
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


