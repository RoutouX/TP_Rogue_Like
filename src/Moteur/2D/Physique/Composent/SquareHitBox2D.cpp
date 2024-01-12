//
// Created by thoma on 08/08/2023.
//

#include "SquareHitBox2D.h"
#include "RoundHitBox2D.h"
#include <math.h>

SquareHitBox2D::SquareHitBox2D(long double width, long double height, long double x, long double y):HitBox(x, y){
    this->width = width;
    this->height = height;
}
SquareHitBox2D::~SquareHitBox2D(){}

bool SquareHitBox2D::itHit(HitBox* pHitBox){
    if (dynamic_cast<SquareHitBox2D*>(pHitBox) != nullptr) {
        long double heightDist = this->distanceYAvec(pHitBox);
        long double widthDist = this->distanceXAvec(pHitBox);
        if (widthDist <= ((this->width / 2) + (dynamic_cast<SquareHitBox2D*>(pHitBox)->getWidth() / 2)) ||
            heightDist <= ((this->height / 2) + (dynamic_cast<SquareHitBox2D*>(pHitBox)->getHeight() / 2))) {
            return true;
        } else {
            return false;
        }
    } else if (dynamic_cast<RoundHitBox2D*>(pHitBox) != nullptr){
        long double circleDistanceX = distanceXAvec(pHitBox);
        long double circleDistanceY = distanceYAvec(pHitBox);
        if (circleDistanceX > (this->getWidth()/2 + dynamic_cast<RoundHitBox2D*>(pHitBox)->getRayon())) { return false; }
        if (circleDistanceY > (this->getHeight()/2 + dynamic_cast<RoundHitBox2D*>(pHitBox)->getRayon())) { return false; }
        if (circleDistanceX <= (this->getWidth()/2)) { return true; }
        if (circleDistanceY <= (this->getHeight()/2)) { return true; }
        double cornerDistance_sq = sqrt(circleDistanceX - this->getWidth()/2) +sqrt(circleDistanceY - this->getHeight()/2);
        return (cornerDistance_sq <= sqrt(dynamic_cast<RoundHitBox2D*>(pHitBox)->getRayon()));
    } else {
        return false;
    }
}




long double SquareHitBox2D::getWidth() const {
    return width;
}
void SquareHitBox2D::setWidth(long double width) {
    SquareHitBox2D::width = width;
}
long double SquareHitBox2D::getHeight() const {
    return height;
}
void SquareHitBox2D::setHeight(long double height) {
    SquareHitBox2D::height = height;
}