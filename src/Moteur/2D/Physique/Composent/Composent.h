//
// Created by thoma on 08/08/2023.
//

#ifndef TP_ROGUE_LIKE_COMPOSENT_H
#define TP_ROGUE_LIKE_COMPOSENT_H

#include <future>

#include "../../../../Utility/Thread.h"
#include "../Map.h"
#include "SquareHitBox2D.h"

class Composent : public Thread, public HitBox{
public:
    Composent(bool* shutdown, bool* pause);
    ~Composent();

    void run(std::future<void> const& stop_token) override;

private:
    void takeVelocityX();
    void takeVelocityY();

    bool* shutdown;
    bool* pause;

    bool takeGravity;
    bool blockingOther;

    long double poids;
    long double velocityX = 0;
    long double velocityY = 0;

    Map* pMap;

};


#endif //TP_ROGUE_LIKE_COMPOSENT_H
