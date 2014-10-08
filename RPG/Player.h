//
//  Player.h
//  kafli5.Rpg
//
//  Created by Sigursteinn Bjarni on 04/10/14.
//  Copyright (c) 2014 Sigursteinn Bjarni. All rights reserved.
//

#ifndef kafli5_Rpg_Player_h
#define kafli5_Rpg_Player_h
#include "Weapon.h"
#include "Monster.h"
#include "Race.h"
#include <string>
#include <vector>

class Monster;

class Player{

public:
    
    //member variables
    Player();
    bool isDead();
    void takeDamage(int damage);
    void createClass();
    bool attack(Monster& monster);
    void levelUp();
    void rest();
    void viewStats();
    void victory(int xp, int gold);
    void gameover();
    void displayHitPoints();
    void pickWeapon(vector<Weapon>& v);
    
    //getter
    string getName();
    int getArmor();
    
    bool isResting;
    
    
private:
    string name;
    string className;
    int accuracy;
    int hitPoints;
    int maxHitPoints;
    int expPoints;
    int nextLevelExp;
    int level;
    int armor;
    int gold;
    Weapon weapon;
    Race race;
    vector<Weapon> weapons;
    
    

};

#endif
