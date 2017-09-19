#include <iostream>
#include <Display.h> // Display includes Map and Tile

using namespace std;

int main()
{
    Tile DefaultTile ('X');
    Map GameMap (3,3,DefaultTile);

    while(true) // Game loop
    {
        DisplayDraw(GameMap);

        break; // Wait for input
    }

    cout << "Hello world!" << endl;
    return 0;
}
