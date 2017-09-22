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
