#include <iostream>
#include <Tile.h>
#include <Map.h>
#include <Display.h>

using namespace std;

int main()
{
    Tile DefaultTile ('X');
    Map GameMap (24,6,DefaultTile);

    //cout << sizeof(DefaultTile) << endl << endl; // Size of a tile object

    while(true) // Game loop
    {
        DisplayDraw(GameMap);

        break; // Wait for input
    }

    return 0;
}
