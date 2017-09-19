#include "Tile.h"

Tile::Tile()
{
    displayCharacter = 'X';
}

Tile::Tile(char DisplayCharacter)
{
    displayCharacter = DisplayCharacter;
}

Tile::~Tile()
{
    //dtor
}
