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
    Faction DefaultFaction ('F');

    GameMap.mapTiles[2 + (2 * 24)].setUnits(8);
    GameMap.mapTiles[2 + (2 * 24)].parentFaction.symbol = 'F';
    GameMap.mapTiles[3 + (4 * 24)].setUnits(3);
    GameMap.mapTiles[3 + (4 * 24)].parentFaction.symbol = 'Q';

    //cout << sizeof(DefaultTile) << endl << endl; // Size of a tile object

    while(true) // Game loop
    {
        DisplayDraw(GameMap);

        while(true)
        {
            cout << "> ";

            movecom inputCommand = commandparser();

            if(GameMap.Move(DefaultFaction, inputCommand))
            {
                break;
            }
            else
            {
                cout << "Invalid move!" << endl;
            }
        }
    }

    return 0;
}
