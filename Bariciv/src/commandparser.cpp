#include "commandparser.h"

movecom commandparser(){
    std::string tile;
    int direct, number;
    std::cin >> tile >> direct >> number;
    movecom a(tile, direct, number);
    return a;
}
