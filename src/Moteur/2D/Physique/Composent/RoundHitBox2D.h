//
// Created by thoma on 11/01/2024.
//

#ifndef TP_ROGUE_LIKE_ROUNDHITBOX2D_H
#define TP_ROGUE_LIKE_ROUNDHITBOX2D_H


#include "HitBox.h"

class RoundHitBox2D: public HitBox{
public:
    //Constructeur destructeur
    RoundHitBox2D(long double rayon, long double x, long double y);
    ~RoundHitBox2D();

    //Methode
    bool itHit(HitBox* pHitBox);

    //Getter and Setter
    long double getRayon() const;
    void setRayon(long double rayon);

private:
    long double rayon = 0;
};


#endif //TP_ROGUE_LIKE_ROUNDHITBOX2D_H
