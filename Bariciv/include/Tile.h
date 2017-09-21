#ifndef TILE_H
#define TILE_H

#include <Faction.h>

struct Tile
{
    public:
        Tile();
        Tile(char DisplayCharacter);
        virtual ~Tile();

        char displayCharacter;
        Faction parentFaction = Faction(' ');
        unsigned char units = 0;
        unsigned char fortifications = 0;

    private:
        void init(char DisplayCharacter);
};

#endif // TILE_H
