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

Map::~Map()
{
    //dtor
}
