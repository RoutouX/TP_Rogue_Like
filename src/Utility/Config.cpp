//
// Created by thoma on 03/08/2023.
//

#include "Config.h"


#include <cstdio>
#include <fstream>
#include <iostream>
#include <filesystem>

#include "fonnct/fonctAdaptOS.h"

Config::Config(std::string fileName){


    pathForOS("test");

    this->fileName = fileName;
    std::filesystem::path cwd = std::filesystem::current_path();

    std::filesystem::path dir ("conf");
    std::filesystem::path file (this->fileName);
    std::fstream cfgFile;
    cfgFile.open(pathForOS((cwd / dir / file).string()), std::ios::in);
    if (cfgFile.is_open()) {
        std::string sa;
        // Read data from the file object and put it into a string.
        while (getline(cfgFile, sa)) {
            // Print the data of the string.
            std::cout << sa << "\n";
        }
        cfgFile.close();
    } else {
        std::cout << "cant read " << this->fileName << "\n";
        exit(0001);
    }
}

std::string Config::getValueOf(std::string name){

}