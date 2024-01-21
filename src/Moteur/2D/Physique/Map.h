//
// Created by thoma on 10/08/2023.
//

#ifndef TP_ROGUE_LIKE_MAP_H
#define TP_ROGUE_LIKE_MAP_H

#include "../../../Utility/Thread.h"
#include "vector"
#include "Composent/Composent.h"


class Map : public Thread{
public:
    /**------------------ CONSTRUCTOR --------------------*/

    Map(bool* pShutdown);
    ~Map();

    /**------------------ METHODE --------------------*/
    void addComposent(Composent* pComposent);
    void deleteComposent(Composent* pComposent);

    void run(std::future<void> const& stop_token) override;

    /**------------------ GETER AND SETER --------------------*/
    const std::vector<Composent*> &getComposentList() const;

    void setComposentList(const std::vector<Composent*> &composentList);

    /**------------------ ATTRIBUT --------------------*/
private:
    bool* pShutdown = nullptr;
    std::vector<Composent*> composentList;
};


#endif //TP_ROGUE_LIKE_MAP_H
