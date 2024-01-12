//
// Created by thoma on 06/08/2023.
//

#ifndef TP_ROGUE_LIKE_POSITION2D_H
#define TP_ROGUE_LIKE_POSITION2D_H


class Position2D {
public:
    Position2D();
    Position2D(long double x, long double y);


    ~Position2D();

    void setX(long double x);
    void setY(long double y);
    void setXY(long double x, long double y);

    long double getX();
    long double getY();

    long double distanceXAvec(Position2D* position2D);
    long double distanceYAvec(Position2D* position2D);
    long double distanceAvec(Position2D* position2D);
    long double distanceAvec(long double x, long double y);

    long double distanceEntre(Position2D* position2D_1, Position2D* position2D_2);
    long double distanceEntre(long double x1, long double y1, long double x2, long double y2);

private:
    long double x; /* mm */
    long double y; /* mm */
};


#endif //TP_ROGUE_LIKE_POSITION2D_H
