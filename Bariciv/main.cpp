#include <iostream>
#include <string>

#include <Tile.h>
#include <Map.h>
#include <Display.h>
#include <movecom.h>
#include <commandparser.h>
#include <ConsoleUI.h>

using namespace std;

int main()
{
    Tile DefaultTile ('X');
    Map GameMap (5,4,DefaultTile);
    Faction DefaultFaction ('F');
    ConsoleUI Console;

    GameMap.GetTile(1, 1).setUnits(8);
    GameMap.GetTile(1, 1).parentFaction.symbol = 'F';
    GameMap.GetTile(1, 1).setFortifications(4);
    GameMap.GetTile(3, 2).setUnits(8);
    GameMap.GetTile(3, 2).parentFaction.symbol = 'Q';
    GameMap.GetTile(3, 2).setFortifications(4);

    //cout << sizeof(DefaultTile) << endl << endl; // Size of a tile object

    char players [] = { 'F', 'Q' };

    const int length = 2;

    while(true) // Game loop
    {
        for(int i = 0; i < length; ++i)
        {
            DisplayDraw(GameMap);

            while(true)
            {
                DefaultFaction.symbol = players[i];

                string playerString = string({DefaultFaction.symbol});

                movecom inputCommand = commandparserString(Console.Prompt(playerString));

                if(GameMap.Move(DefaultFaction, inputCommand))
                {
                    break;
                }
                else
                {
                    Console.Message("Invalid move!");
                }
            }
        }
    }

    return 0;
}
