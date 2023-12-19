#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main ()
{
  srand( (unsigned)time(NULL) );

  float attackLevel, effectiveAttackLevel, attackRollMax, combatStyleAttackBoost, equipmentAttackBonus, hitChance, hitChanceFixed, hitRoll;
  float strengthLevel, effectiveStrengthLevel, combatStyleStrengthBoost, maximumDamageHit, equipmentStrengthBonus, damageRoll, damage;
  float monsterDefenceLevel, defenceRollMax, monsterHealth;
  signed monsterDefenceStyleBonus;
  bool attackFavored;

  attackLevel = 1;
  strengthLevel = 1;
  combatStyleAttackBoost = 3;
  combatStyleStrengthBoost = 3;
  equipmentAttackBonus = 5;
  equipmentStrengthBonus = 7;
  damage = 1;
  monsterHealth = 5;

//Effective attack level and the resulting max attack roll value
  effectiveAttackLevel = attackLevel + combatStyleAttackBoost + 8;
  attackRollMax = effectiveAttackLevel * (equipmentAttackBonus + 64);
//Effective strength and how that translates to damage value
  effectiveStrengthLevel = strengthLevel + combatStyleStrengthBoost + 8;
  maximumDamageHit = floor((((effectiveStrengthLevel * (equipmentStrengthBonus + 64)) + 320) / 640));

  // std::cout << maximumDamageHit;
  // std::cout << "\n";

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
  // std::cout << hitChanceFixed;
  // std::cout << "\n";

  while (monsterHealth > 0)
  {
    hitRoll = rand();
    // std::cout << hitRoll;
    // std::cout << "\n";
    if (hitRoll < hitChanceFixed)
    {
      std::cout << "Hit \n";
      damageRoll = rand();
      // std::cout << damageRoll;
      // std::cout << "\n";
      if (damageRoll > 16385)
      {
        monsterHealth = monsterHealth - maximumDamageHit;
          std::cout << maximumDamageHit << " damage dealt \n";
          std::cout << "Monster Health ";
          std::cout << monsterHealth;
          std::cout << "\n";
      }
      else
      {
        std::cout << "No Damage! \n";
      }
    }
    else
    {
      std::cout << "Miss \n";
    }
  }

  // terminate the program:
  return 0;
}