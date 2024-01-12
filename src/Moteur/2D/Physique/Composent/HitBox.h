//
// Created by thoma on 11/01/2024.
//

#ifndef TP_ROGUE_LIKE_HITBOX_H
#define TP_ROGUE_LIKE_HITBOX_H


#include "../../Utility/Position2D.h"

class HitBox: public Position2D{
public:
    //Constructeur destructeur
    HitBox(long double x, long double y);

    ~HitBox();

    //Methode
    virtual bool itHit(HitBox* pHitBox);


private:
};


#endif //TP_ROGUE_LIKE_HITBOX_H
