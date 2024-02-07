//
// Created by thoma on 08/08/2023.
//

#include "RoundHitBox2D.h"
#include "Composent.h"
#include "vector"

#include "../Map.h"

Composent::Composent(bool *shutdown, long double rayon, long double x, long double y, bool blockingOther): RoundHitBox2D(rayon, x, y) {

    this->shutdown = shutdown;

    this->blockingOther = blockingOther;

    long double velocityX = 0; /* mm/ms */
    long double velocityY = 0;/* mm/ms */
}




void Composent::run(std::future<void> const& stop_token) {
    uint64_t last = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    while (!is_stop_requested(stop_token) && !*this->shutdown) {
        if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() >= last+2){
            uint64_t newLast = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            uint64_t delta = newLast - last;
            this->setX(this->getX() + velocityX * delta);
            this->setY(this->getY() + velocityY * delta);
            last = newLast;
            if (pMap != nullptr){
                std::vector<Composent*> componentList= pMap->getComposentList();
                for(Composent* c: componentList){
                    if (c != this) {
                        if (c->itHit(this)) {
                            std::cout << "its hit : " << c << "<>" << this << std::endl;
                            c->onGetHit(this);
                            this->onGetHit(c);
                        }else{
                            std::cout << "no hit : " << c << "<>" << this << std::endl;
                        }
                    }
                    else{
                        std::cout << "its self" << std::endl;
                    }
                }
            }else{
                std::cout << "no map" << std::endl;
            }
        }
    }
    *this->shutdown = true;
}

void Composent::onGetHit(Composent* c) {
    setVelocityX(0);
    setVelocityY(0);
}












bool *Composent::getShutdown() const {
    return shutdown;
}

void Composent::setShutdown(bool *shutdown) {
    Composent::shutdown = shutdown;
}



bool Composent::isTakeGravity() const {
    return takeGravity;
}

void Composent::setTakeGravity(bool takeGravity) {
    Composent::takeGravity = takeGravity;
}

bool Composent::isBlockingOther() const {
    return blockingOther;
}

void Composent::setBlockingOther(bool blockingOther) {
    Composent::blockingOther = blockingOther;
}

long double Composent::getPoids() const {
    return poids;
}

void Composent::setPoids(long double poids) {
    Composent::poids = poids;
}

long double Composent::getVelocityX() const {
    return velocityX;
}

void Composent::setVelocityX(long double velocityX) {
    Composent::velocityX = velocityX;
}

long double Composent::getVelocityY() const {
    return velocityY;
}

void Composent::setVelocityY(long double velocityY) {
    Composent::velocityY = velocityY;
}

void Composent::setPMap(Map *pMap) {
    Composent::pMap = pMap;
}

Composent::~Composent() {

}

Map *Composent::getPMap() const {
    return pMap;
}

