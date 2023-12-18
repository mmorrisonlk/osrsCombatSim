#include <iostream>
using namespace std;

int main ()
{
  int attackLevel, effectiveAttackLevel, attackRollMax, combatStyleBoost, equipmentAttackBonus, monsterDefenceLevel, defenceRollMax;
  signed monsterDefenceStyleBonus;
  bool attackFavored;

  attackLevel = 1;
  combatStyleBoost = 3;
  equipmentAttackBonus = 5;

  effectiveAttackLevel = attackLevel + combatStyleBoost + 8;
  attackRollMax = effectiveAttackLevel * (equipmentAttackBonus + 64);
  // std::cout << attackRollMax;

  monsterDefenceLevel = 1;
  monsterDefenceStyleBonus = -15;
  defenceRollMax = (monsterDefenceLevel + 9) * (monsterDefenceStyleBonus + 64);
  // std::cout << defenceRollMax;

  if (attackRollMax > defenceRollMax)
  {
    attackFavored = true;
  }
  else {
    attackFavored = false;
  }
  std::cout << attackFavored;
  

  // while (enemyHealth > 0)
  // {
  //   enemyHealth = enemyHealth - attack;
  //     std::cout << enemyHealth;
  // }

  // terminate the program:
  return 0;
}