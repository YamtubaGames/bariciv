#include "commandparser.h"

movecom commandparser(std::istream &inputStream){
    std::string tile;
    int direct, number;
    inputStream >> tile >> number >> direct;
    movecom a(tile, number, direct);
    return a;
}

movecom commandparserString(std::string input)
{
    std::istringstream iss (input);
    return commandparser(iss);
}
