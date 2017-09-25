#include "movecom.h"
using namespace std;

movecom::movecom(std::string tile, int numberof, int direction)
{
    direct = direction;
    number = numberof;
    std::string a, b;
    a = tile.substr(0,1);
    tile.erase(0,1);
    b = tile;
    std::string hello[30] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30"};
    for(int i = 0; i < 30; i++) {
        if (b == hello[i]) {
            row = i;
            i = 30;
        };
    };
    std::string hi[52] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    for(int i = 0; i < 52; i++) {
        if (a == hi[i]) {
            column = i % 26;
            i = 52;
        };
    };
}

movecom::~movecom()
{
    //dtor
}

void movecom::print() {
    std::cout << row << endl << column << endl << direct << endl << number << endl;
}
