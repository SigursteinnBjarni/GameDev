//
//  Monster.cpp
//  kafli5.Rpg
//
//  Created by Sigursteinn Bjarni on 04/10/14.
//  Copyright (c) 2014 Sigursteinn Bjarni. All rights reserved.
//

#include <iostream>
#include "Monster.h"
#include "Weapon.h"
#include "Random.h"
#include "Player.h"
#include <string>

//"Orc", 10, 8, 200, 1, "Short Sword", 2, 7

Monster::Monster(){}

Monster::Monster(const std::string& name, int hp, int acc,
                 int xpReward, int armor, const std::string& weaponName,
                 int lowDamage, int highDamage, int goldReward)
{
    this->name = name;
    this->hitPoints = hp;
    this->accuracy = acc;
    this->xpReward = xpReward;
    this->armor = armor;
    this->weapon.weaponName = weaponName;
    this->weapon.dmgRange.low = lowDamage;
    this->weapon.dmgRange.high = highDamage;
    this->goldReward = goldReward;

}
bool Monster::isDead(){
    return hitPoints <= 0;
}
int Monster::getXpReward(){
    return xpReward;
    
}

int Monster::getGoldReward(){
    return goldReward;
}
string Monster::getName(){
    return name;
}
int Monster::getArmor(){
    return armor;
}

void Monster::attack(Player& player){
    cout << "A spooky " << getName() << " attacks you! " << "he vields a deadly "
    << weapon.weaponName << endl;
    
    if (Random(1, 20) < accuracy) {
        int damage = Random(weapon.dmgRange);
        int totalDamage = damage - player.getArmor();
            if( totalDamage <= 0 )
            {
                cout << "The monster's attack failed to " << "penetrate your armor." << endl;
            }
            else
            {
                cout << "You are hit for " << totalDamage << " damage!" << endl;
                player.takeDamage(totalDamage);
            }
        
    }
    else{
        cout << "The " << getName() << " swings foolishly and misses." << endl;
    }
    
    cout << endl;
    
}
void Monster::takeDamage(int damage){
    hitPoints -= damage;
}

void Monster::displayHitPoints(){
    cout << name << "'s hitpoints = " << hitPoints << endl;
}
