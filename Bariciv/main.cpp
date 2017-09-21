#include <iostream>
#include <Tile.h>
#include <Map.h>
#include <Display.h>
#include <movecom.h>
#include <commandparser.h>
#include <string>

using namespace std;

int main()
{
    Tile DefaultTile ('X');
    Map GameMap (24,6,DefaultTile);

    //cout << sizeof(DefaultTile) << endl << endl; // Size of a tile object

    while(true) // Game loop
    {
        DisplayDraw(GameMap);

        movecom inputCommand = commandparser();
        break;
    }

    return 0;
}
