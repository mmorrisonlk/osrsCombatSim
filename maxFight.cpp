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
    float swingTimer, battleTime, totalBattleTime, averageTime, fights, superCombatBoost, prayerAttackBonus, prayerStrengthBonus;
    signed monsterDefenceStyleBonus;
    bool attackFavored;

    attackLevel = 99;
    strengthLevel = 99;
    superCombatBoost = 19;
    prayerAttackBonus = 1.2;
    prayerStrengthBonus = 1.23;
    combatStyleAttackBoost = 0;
    combatStyleStrengthBoost = 3;
  //Torture, Primordial, Infernal Cape, Avernic, Ferocious, Ghrazi Rapier
    equipmentAttackBonus = 161;
  //Full Torva, Torture, Primordial, Infernal Cape, Avernic, Ferocious, Ultor, Ghrazi Rapier
    equipmentStrengthBonus = 164;
    swingTimer = 2.4;
    battleTime = 0;
    totalBattleTime = 0;
    fights = 0;
    damage = 1;
    monsterHealth = 330;

//Effective attack level and the resulting max attack roll value
    effectiveAttackLevel = (floor((attackLevel + superCombatBoost) * prayerAttackBonus) + combatStyleAttackBoost + 8);
    attackRollMax = effectiveAttackLevel * (equipmentAttackBonus + 64);
//Effective strength and how that translates to damage value
    effectiveStrengthLevel = (floor((strengthLevel + superCombatBoost) * prayerStrengthBonus) + combatStyleStrengthBoost + 8);
    maximumDamageHit = floor((((effectiveStrengthLevel * (equipmentStrengthBonus + 64)) + 320) / 640));

//Monster defensive stats calculation
  monsterDefenceLevel = 276;
  monsterDefenceStyleBonus = 30;
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

  while(fights < 1000)
  {
    //While monster is not dead keep hitting it
  while (monsterHealth > 0)
  {
    //Random hit roll
    hitRoll = rand();
    battleTime = battleTime + swingTimer;
    if (hitRoll < hitChanceFixed)
    {
    //   std::cout << "Hit \n";
      damageRoll = rand();
      //Monkey Patch damage roll
      if (damageRoll > 585)
      {
        monsterHealth = monsterHealth - (floor((damageRoll / 585)) * 1);
        //   std::cout << "Monster Health ";
        //   std::cout << monsterHealth;
        //   std::cout << "\n";
      }
      else
      {
        // std::cout << "No Damage! \n";
      }
    }
    else
    {
    //   std::cout << "Miss \n";
    }
  } 
    trialResults.push_back(battleTime);
    monsterHealth = 330;
    battleTime = 0;
    fights = fights + 1;
  }

  for (double n : trialResults) {
    totalBattleTime = totalBattleTime + n;
  }

  averageTime = (totalBattleTime / trialResults.size());
    std::cout << averageTime;
  // terminate the program:
  return 0;
}