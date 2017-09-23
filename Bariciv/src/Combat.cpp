#include "Combat.h"

void Combat(Tile &FromTile, Tile &ToTile, int numberSent, double randomA, double randomB)
{
    int troopsLeft = FromTile.getUnits() - numberSent;
    if(troopsLeft < 0)
        troopsLeft = 0;

    double attackerCount;

    if(numberSent > FromTile.getUnits())
        attackerCount = (double)FromTile.getUnits();
    else
        attackerCount = (double)numberSent;

    if(FromTile.parentFaction.symbol == ToTile.parentFaction.symbol)
    {
        FromTile.setUnits(troopsLeft);
        ToTile.setUnits(ToTile.getUnits() + (int)attackerCount);
        return;
    }

    if(ToTile.getUnits() == 0)
    {
        FromTile.setUnits(troopsLeft);
        ToTile.setUnits(ToTile.getUnits() + (int)attackerCount);
        ToTile.parentFaction.symbol = FromTile.parentFaction.symbol;
        return;
    }

    double defenderCount = (double)ToTile.getUnits();
    int fortifications = ToTile.getFortifications();

    double biggerLuck = (randomA * 0.5d) + 0.5d;
    double smallerLuck = (randomB * 0.5d);

    const double fortificationCoefficient = 0.1d;

    double fortificationBonus = 1.0d + (fortifications * fortificationCoefficient);

    double defenderCountEffective = defenderCount * fortificationBonus;

    bool moreAttackers;

    int difference;

    if(attackerCount > defenderCountEffective)
    {
        moreAttackers = true;
        difference = attackerCount - defenderCountEffective;
    }
    else
    {
        moreAttackers = false;
        difference = defenderCountEffective - attackerCount;
    }

    ++difference;

    if(moreAttackers)
    {
        attackerCount -= biggerLuck * difference;
        defenderCount -= smallerLuck * difference;
    }
    else
    {
        attackerCount -= smallerLuck * difference;
        defenderCount -= biggerLuck * difference;
    }

    int attackerOut = (int)attackerCount;
    int defenderOut = (int)defenderCount;

    if(attackerOut < 0)
        attackerOut = 0;

    if(defenderOut < 0)
        defenderOut = 0;

    if(defenderOut == 0 && attackerOut != 0)
    {
        ToTile.parentFaction.symbol = FromTile.parentFaction.symbol;
        ToTile.setUnits(attackerOut);
        FromTile.setUnits(troopsLeft);
    }
    else
    {
        ToTile.setUnits(defenderOut);
        FromTile.setUnits(troopsLeft + attackerOut);
    }

    ToTile.setFortifications(fortifications - 1);

    if(ToTile.getFortifications() < 0)
    {
        ToTile.setFortifications(0);
    }
}
