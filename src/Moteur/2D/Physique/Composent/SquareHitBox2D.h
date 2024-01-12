//
// Created by thoma on 08/08/2023.
//

#ifndef TP_ROGUE_LIKE_HITBOX2D_H
#define TP_ROGUE_LIKE_HITBOX2D_H

#include "../../Utility/Position2D.h"
#include "HitBox.h"

class SquareHitBox2D: public HitBox{
public:
    //Constructeur destructeur
    SquareHitBox2D(long double width, long double height, long double x, long double y);

    ~SquareHitBox2D();

    //Methode
    bool itHit(HitBox* pHitBox) override;

    //Getter and Setter
    long double getWidth() const;

    void setWidth(long double width);

    long double getHeight() const;

    void setHeight(long double height);

private:
    long double width = 0; /* mm */
    long double height = 0; /* mm */
};


#endif //UNNAMEDGAME_HITBOX2D_H
