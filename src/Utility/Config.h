//
// Created by thoma on 03/08/2023.
//

#ifndef TP_ROGUE_LIKE_CONFIG_H
#define TP_ROGUE_LIKE_CONFIG_H

#include <vector>
#include <string>

struct PARAMETRE {
    std::string name;
    std::string value;
};

class Config {

public:
    Config(std::string fileName);
    std::string getValueOf(std::string name);
private:
    std::string fileName;
    std::vector<PARAMETRE> parametres;

};


#endif //TP_ROGUE_LIKE_CONFIG_H
