#include "commandparser.h"

movecom commandparser(std::istream &inputStream){
    std::string tile;
    int direct, number;
    inputStream >> tile >> direct >> number;
    movecom a(tile, direct, number);
    return a;
}

movecom commandparserString(std::string input)
{
    std::istringstream iss (input);
    return commandparser(iss);
}
