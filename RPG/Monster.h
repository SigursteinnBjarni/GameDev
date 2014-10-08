//
//  Monster.h
//  kafli5.Rpg
//
//  Created by Sigursteinn Bjarni on 04/10/14.
//  Copyright (c) 2014 Sigursteinn Bjarni. All rights reserved.
//

#ifndef kafli5_Rpg_Monster_h
#define kafli5_Rpg_Monster_h
#include "Weapon.h"
#include <string>

class Player;


class Monster{
public:
    Monster();
    Monster(const std::string& name, int hp, int acc,
            int xpReward, int armor, const std::string& weaponName,
            int lowDamage, int highDamage, int goldReward);
    bool isDead();
    int getXpReward();
    int getGoldReward();
    string getName();
    int getArmor();
    
    void attack(Player& player);
    void takeDamage(int damage);
    void displayHitPoints();
    
private:
    string name;
    int hitPoints;
    int accuracy;
    int xpReward;
    int armor;
    int goldReward;
    Weapon weapon;




};

#endif
