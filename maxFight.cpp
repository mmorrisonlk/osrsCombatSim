#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main ()
{
  srand( (unsigned)time(NULL) );

  float attackLevel, effectiveAttackLevel, attackRollMax, combatStyleAttackBoost, equipmentAttackBonus, hitChance, hitChanceFixed, hitRoll;
  float strengthLevel, effectiveStrengthLevel, combatStyleStrengthBoost, maximumDamageHit, equipmentStrengthBonus, damageRoll, damage;
  float monsterDefenceLevel, defenceRollMax, monsterHealth;
  float swingTimer, battleTime, fights;
  signed monsterDefenceStyleBonus;
  bool attackFavored;

  attackLevel = 1;
  strengthLevel = 1;
  combatStyleAttackBoost = 3;
  combatStyleStrengthBoost = 3;
  equipmentAttackBonus = 5;
  equipmentStrengthBonus = 7;
  swingTimer = 2.4;
  battleTime = 0;
  fights = 0;
  damage = 1;
  monsterHealth = 5;

//Effective attack level and the resulting max attack roll value
  effectiveAttackLevel = attackLevel + combatStyleAttackBoost + 8;
  attackRollMax = effectiveAttackLevel * (equipmentAttackBonus + 64);
//Effective strength and how that translates to damage value
  effectiveStrengthLevel = strengthLevel + combatStyleStrengthBoost + 8;
  maximumDamageHit = floor((((effectiveStrengthLevel * (equipmentStrengthBonus + 64)) + 320) / 640));

//Monster defensive stats calculation
  monsterDefenceLevel = 1;
  monsterDefenceStyleBonus = -15;
  defenceRollMax = (monsterDefenceLevel + 9) * (monsterDefenceStyleBonus + 64);
//Checks for attack or defence being higher to determine the combat formula used 
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

  //Monkey Patch hit chance
  hitChanceFixed = 32767 * hitChance;

  std::vector<double> trialResults = {};

  while(fights < 5)
  {
  //While monster is not dead keep hitting it
  while (monsterHealth > 0)
  {
    //Random hit roll
    hitRoll = rand();
    battleTime = battleTime + swingTimer;
    if (hitRoll < hitChanceFixed)
    {
      std::cout << "Hit \n";
      damageRoll = rand();
      //Monkey Patch damage roll
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
    trialResults.push_back(battleTime);
    monsterHealth = 5;
    battleTime = 0;
    fights = fights + 1;
  }

  for (double n : trialResults)
        std::cout << n << ' ';
    std::cout << '\n';
  // terminate the program:
  return 0;
}