#ifndef FACTION_H
#define FACTION_H


class Faction
{
    public:
        Faction(char Symbol);
        virtual ~Faction();

        char symbol;

    protected:

    private:
};

const Faction blankFaction (' ');

#endif // FACTION_H
