//
// Created by thoma on 06/08/2023.
//

#include "fonctManipulateString.h"

std::string replaceAllSubstringOccurrences(std::string innitialString, std::string sStringToRemove, std::string sStringToInsert)
{
    int iLength = sStringToRemove.length();
    size_t index = 0;
    while (true)
    {
        /* Locate the substring to replace. */
        index = innitialString.find(sStringToRemove, index);
        if (index == std::string::npos)
            break;

        /* Make the replacement. */
        innitialString.replace(index, iLength, sStringToInsert);

        /* Advance index forward so the next iteration doesn't pick it up as well. */
        index += iLength;
    }
    return innitialString;
}