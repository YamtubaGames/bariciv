#include "Display.h"
#include <iostream>

using namespace std;

void DisplayDraw(Map &OutputMap)
{
    //stringbuf buffer;

    /*  SIMPLE METHOD
    for(int y = 0; y < OutputMap.height; ++y)
    {
        for(int x = 0; x < OutputMap.width; ++ x)
        {
            cout << OutputMap.mapTiles[x + (y * OutputMap.width)].displayCharacter;
        }
        cout << endl;
    }
    */

    // Your mom's method

    cout << "|";

    for(int x = 0; x < OutputMap.width - 1; ++ x)
    {
        cout << "---";
    }

    cout << "--|" << endl;

    for(int y = 0; y < OutputMap.height; ++y)
    {

        for(int x = 0; x < OutputMap.width; ++ x)
        {
            cout << "|" << OutputMap.mapTiles[x + (y * OutputMap.width)].getUnits() << OutputMap.mapTiles[x + (y * OutputMap.width)].parentFaction.symbol;
        }
        cout << "|" << endl;

        for(int x = 0; x < OutputMap.width; ++ x)
        {
            cout << "|" << OutputMap.mapTiles[x + (y * OutputMap.width)].displayCharacter << OutputMap.mapTiles[x + (y * OutputMap.width)].getFortifications();
        }
        cout << "|" << endl;

        cout << "|";

        for(int x = 0; x < OutputMap.width - 1; ++ x)
        {
            cout << "---";
        }

        cout << "--|" << endl;
    }

    //cout << buffer;

    //cout << "|--|--|" << endl << "|32|40|" << endl << "|PQ|PF|" << endl << "|--|--|" << endl;
    //cout << endl << "|-----|" << endl << "|32|40|" << endl << "|PQ|PF|" << endl << "|-----|" << endl;
}
