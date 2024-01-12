//
// Created by thoma on 06/08/2023.
//

#include "fonctAdaptOS.h"

#include <string>
#include <iostream>

#include "fonctManipulateString.h"


std::string pathForOS(std::string path){
    #ifdef _WIN32 || _WIN64
        return replaceAllSubstringOccurrences(path, "/", "\\");
    #elif __APPLE__ || __MACH__
        return replaceAllSubstringOccurrences(path, "\\", "/");
    #elif __linux__
        return replaceAllSubstringOccurrences(path, "\\", "/");
    #else
        exit(666);
    #endif
}
