#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main ()
{
  srand( (unsigned)time(NULL) );

  float attackLevel, effectiveAttackLevel, attackRollMax, combatStyleBoost, equipmentAttackBonus, monsterDefenceLevel, defenceRollMax, hitChance, hitChanceFixed, hitRoll, damage, monsterHealth;
  signed monsterDefenceStyleBonus;
  bool attackFavored;

  attackLevel = 1;
  combatStyleBoost = 3;
  equipmentAttackBonus = 5;
  damage = 1;
  monsterHealth = 5;

  effectiveAttackLevel = attackLevel + combatStyleBoost + 8;
  attackRollMax = effectiveAttackLevel * (equipmentAttackBonus + 64);

  monsterDefenceLevel = 1;
  monsterDefenceStyleBonus = -15;
  defenceRollMax = (monsterDefenceLevel + 9) * (monsterDefenceStyleBonus + 64);

  if (attackRollMax > defenceRollMax)
  {
    attackFavored = true;
  }
  else
  {
    attackFavored = false;
  }
  
  if (attackFavored == true)
  {
    hitChance = (1 - ((defenceRollMax + 2)/(2 * (attackRollMax + 1))));
  }
  else
  {
    hitChance = (attackRollMax / (2 * (defenceRollMax + 1)));
  }

  hitChanceFixed = 32767 * hitChance;
  std::cout << hitChanceFixed;
  std::cout << "\n";

  while (monsterHealth > 0)
  {
    hitRoll = rand();
    std::cout << hitRoll;
    std::cout << "\n";
    if (hitRoll < hitChanceFixed)
    {
      monsterHealth = monsterHealth - damage;
      std::cout << monsterHealth;
      std::cout << "\n";
    }
    else
    {
      std::cout << "Miss \n";
    }
  }

  // terminate the program:
  return 0;
}