#ifndef TILE_H
#define TILE_H


struct Tile
{
    public:
        Tile();
        Tile(char DisplayCharacter);
        virtual ~Tile();

        char displayCharacter;

    protected:

    private:
};

#endif // TILE_H
