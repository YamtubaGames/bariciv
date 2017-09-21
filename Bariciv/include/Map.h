#ifndef MAP_H
#define MAP_H

#include <Tile.h>

class Map
{
    public:
        Map(int width, int height, Tile defaultTile);
        virtual ~Map();

        void Fill(Tile TileToFill);

        Tile* mapTiles;
        int width, height;

        bool CoordIsInBounds(int x, int y);
        bool Move(Faction Player, int x, int y, int dir, int units);

    protected:

    private:
};

#endif // MAP_H
