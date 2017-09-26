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
        ToTile.setUnits((int)attackerCount);
        ToTile.parentFaction.symbol = FromTile.parentFaction.symbol;
        return;
    }

    double defenderCount = (double)ToTile.getUnits();
    int fortifications = ToTile.getFortifications();

    double biggerLuck = (randomA * 0.5d) + 0.5d;
    double smallerLuck = (randomB * 0.5d);

    const double fortificationCoefficient = 0.1d;
    double fortificationBonus = 0.5d * (fortifications * fortificationCoefficient);

    bool moreAttackers;

    double difference;

    if(attackerCount > defenderCount)
    {
        moreAttackers = true;
        difference = attackerCount - defenderCount;
    }
    else
    {
        moreAttackers = false;
        difference = defenderCount - attackerCount;
    }

    ++difference;

    if(moreAttackers)
    {
        attackerCount -= smallerLuck * difference;
        double defenderLosses = biggerLuck * difference;
        defenderCount -= defenderLosses - (defenderLosses * fortificationBonus);
    }
    else
    {
        attackerCount -= biggerLuck * difference;
        double defenderLosses = smallerLuck * difference;
        defenderCount -= defenderLosses - (defenderLosses * fortificationBonus);
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
