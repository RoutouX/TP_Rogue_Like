//
// Created by thoma on 10/08/2023.
//

#include "Map.h"
#include "Composent/Composent.h"

#include <algorithm>
#include <valarray>


Map::Map(bool* pShutdown) : pShutdown(pShutdown) {}

Map::~Map() {
    for (Composent* composent : this->composentList){
        delete composent;
    }
}

void Map::addComposent(Composent* pComposent) {
    this->composentList.push_back(pComposent);
}

void Map::deleteComposent(Composent *pComposent) {
    this->composentList.erase(std::remove(composentList.begin(), composentList.end(), pComposent), composentList.end());
}

void Map::run(const std::future<void> &stop_token) {
    for (int i = 0; i < size(composentList) ; ++i) {
        composentList[i]->start();
    }
}










const std::vector<Composent *> &Map::getComposentList() const {
    return composentList;
}

void Map::setComposentList(const std::vector<Composent *> &composentList) {
    Map::composentList = composentList;
}

