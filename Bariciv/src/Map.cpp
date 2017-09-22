#include "Map.h"

Map::Map(int width, int height, Tile defaultTile)
{
    if(width < 1 || height < 1)
        throw "Arguments out of range!";

    Map::width = width;
    Map::height = height;

    mapTiles = new Tile[width * height];

    Fill(defaultTile);
}

void Map::Fill(Tile TileToFill)
{
    for(int x = 0; x < width; ++x)
    {
        for(int y = 0; y < height; ++ y)
        {
            mapTiles[x + (y * width)] = TileToFill;
        }
    }
}

bool Map::CoordIsInBounds(int x, int y)
{
    if(x < 0 || y < 0 || x > width || y > width)
        return false;
    return true;
}

bool Map::Move(Faction Player, int x, int y, int dir, int units)
{
    if(!CoordIsInBounds(x, y))
        return false;

    int xN = x, yN = y;

    switch(dir)
    {
        case 0:
            --yN;
            break;
        case 1:
            ++xN;
            break;
        case 2:
            ++yN;
            break;
        case 3:
            --xN;
            break;
        default:
            return false;
    }

    if(!CoordIsInBounds(xN, yN))
        return false;

    // Calculate results
    Tile *fromTile = &mapTiles[x + (y * width)];
    Tile *toTile = &mapTiles[xN + (yN * width)];

    return true;
}

bool Map::Move(Faction Player, movecom Command)
{
    return Move(Player, Command.getcolumn(), Command.getrow(), Command.getdirect(), Command.getnumber());
}

Map::~Map()
{
    delete [] mapTiles;
    mapTiles = 0;
}
