//
// Created by thoma on 06/08/2023.
//

#include "Position2D.h"

#include <cmath>


Position2D::Position2D(){
    this->x = 0;
    this->y = 0;
}
Position2D::Position2D(long double x, long double y){
    this->x = x;
    this->y = y;
}

Position2D::~Position2D(){}

void Position2D::setX(long double x){
    this->x = x;
}
void Position2D::setY(long double y){
    this->y = y;
}
void Position2D::setXY(long double x, long double y){
    this->x = x;
    this->y = y;
}

long double Position2D::getX(){
    return x;
}
long double Position2D::getY(){
    return y;
}

long double Position2D::distanceXAvec(Position2D* position2D){
    return abs(position2D->getX() - this->x);
}
long double Position2D::distanceYAvec(Position2D* position2D){
    return abs(position2D->getY() - this->y);
}

long double Position2D::distanceAvec(Position2D* position2D){
    return sqrt(pow((position2D->getX() - this->x), 2) + pow((position2D->getY() - this->y), 2));
}
long double Position2D::distanceAvec(long double x, long double y){
    return sqrt(pow((x- this->x), 2)+pow((y- this->y), 2));
}

long double Position2D::distanceEntre(Position2D* position2D_1, Position2D* position2D_2){
    return sqrt(pow((position2D_1->getX() - position2D_2->getX()), 2)+pow((position2D_1->getY() - position2D_2->getY()), 2));
}
long double Position2D::distanceEntre(long double x1, long double y1, long double x2, long double y2){
    return sqrt(pow((x1 - x2), 2)+pow((y1 - y2), 2));

}