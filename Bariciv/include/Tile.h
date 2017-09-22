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
        Faction parentFaction = Faction('U');

        int getUnits() {return units;};
        int getFortifications() {return fortifications;};
        bool setUnits(int Number) {if(Number >= 0 && Number <= 9) {units = Number; return true;} else {return false;}};
        bool setFortifications(int Number) {if(Number >= 0 && Number <= 9) {units = Number; return true;} else {return false;}};

    private:
        void init(char DisplayCharacter);

        int units = 0;
        int fortifications = 0;
};

#endif // TILE_H
