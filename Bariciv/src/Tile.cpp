#include "Tile.h"

Tile::Tile()
{
    init('X');
}

Tile::Tile(char DisplayCharacter)
{
    init(DisplayCharacter);
}

void Tile::init(char DisplayCharacter)
{
    displayCharacter = DisplayCharacter;
    //parentFaction = new Faction(' '); // Allocate this to the stack instead of the heap?
}

Tile::~Tile()
{
    //delete parentFaction; // This being disabled may create a leak
}
