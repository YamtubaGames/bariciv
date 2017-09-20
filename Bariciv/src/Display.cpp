#include "Display.h"
#include <iostream>

using namespace std;

void DisplayDraw(Map &OutputMap)
{
    for(int y = 0; y < OutputMap.height; ++y)
    {
        for(int x = 0; x < OutputMap.width; ++ x)
        {
            cout << OutputMap.mapTiles[x + (y * OutputMap.width)].displayCharacter;
        }
        cout << endl;
    }
}
