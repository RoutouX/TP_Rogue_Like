//
// Created by thoma on 08/08/2023.
//

#ifndef TP_ROGUE_LIKE_COMPOSENT_H
#define TP_ROGUE_LIKE_COMPOSENT_H

#include "../../../../Utility/Thread.h"
#include "RoundHitBox2D.h"

class Map;

class Composent : public Thread, public RoundHitBox2D{
public:

    /**------------------ CONSTRUCTOR --------------------*/
    Composent(bool *shutdown, long double rayon, long double x, long double y, bool blockingOther);
    ~Composent();


    /**------------------ METHODE --------------------*/
    void onGetHit(Composent* c);
    void run(std::future<void> const& stop_token) override;

    /**------------------ GETER AND SETER --------------------*/

    bool *getShutdown() const;

    void setShutdown(bool *shutdown);

    Map *getPMap() const;

    bool isTakeGravity() const;

    void setTakeGravity(bool takeGravity);

    bool isBlockingOther() const;

    void setBlockingOther(bool blockingOther);

    long double getPoids() const;

    void setPoids(long double poids);

    long double getVelocityX() const;

    void setVelocityX(long double velocityX);

    long double getVelocityY() const;

    void setVelocityY(long double velocityY);

    void setPMap(Map* pMap);

    /**------------------ ATTRIBUT --------------------*/

private:

    bool* shutdown;

    bool takeGravity;
    bool blockingOther;

    long double poids;
    long double velocityX = 0;
    long double velocityY = 0;

    Map* pMap = nullptr;

};


#endif //TP_ROGUE_LIKE_COMPOSENT_H
