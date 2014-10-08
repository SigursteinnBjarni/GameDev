//
//  Player.cpp
//  kafli5.Rpg
//
//  Created by Sigursteinn Bjarni on 04/10/14.
//  Copyright (c) 2014 Sigursteinn Bjarni. All rights reserved.
//

#include "Player.h"
#include "Weapon.h"
#include "Range.h"
#include "Random.h"
#include "Map.h"
#include <iostream>
#include <string>
using namespace std;

Weapon wep;
Weapon wep2;

Player::Player()
{
    this->name = "Default";
    this->className = "Default";
    this->accuracy = 0;
    this->armor = 0;
    this->expPoints = 0;
    this->hitPoints = 0;
    this->level = 0;
    this->maxHitPoints = 0;
    this->weapon.dmgRange.high = 0;
    this->weapon.dmgRange.low = 0;
    this->weapon.weaponName = "Default weapon name";
    this->gold = 2;
    this->race.raceName = "Default ";
    this->isResting = false;
    
    
    wep2.weaponName = "The secret Weapon";
    wep2.dmgRange.high = 20;
    wep2.dmgRange.low = 10;
    weapons.push_back(wep2);
    
}

bool Player::isDead()
{
    return hitPoints <= 0;
}

int Player::getArmor()
{
    return armor;
}

void Player::takeDamage(int damage)
{
    armor -= damage;
    if(armor <= 0){
        hitPoints -= damage;
    }
}

void Player::createClass()
{
    cout << "CHARACTER CLASS GENERATION" << endl;
    cout << "==========================" << endl;
    cout <<"Enter in your characters name: ";
    getline(cin, name);
    // Character selection.
    cout << "Please select a character class number..."<< endl;
    cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";
    
    
    int characterNum = 0;
    cin >> characterNum;
    
    switch( characterNum ){
    case 1:
        className = "Warrior";
        accuracy = 10;
        hitPoints = 15;
        maxHitPoints = 20;
        expPoints = 0;
        nextLevelExp = 1000;
        level = 1;
        armor = 5;
        wep.weaponName = "Sword";
        wep.dmgRange.low = 3;
        wep.dmgRange.high = 8;
        weapons.push_back(wep);
        break;
            
    case 2:  //Wizard
        className = "Wizard";
        accuracy = 10;
        hitPoints = 10;
        maxHitPoints = 15;
        expPoints = 0;
        nextLevelExp = 1000;
        level = 1;
        armor = 5;
        wep.weaponName = "Orb";
        wep.dmgRange.low = 2;
        wep.dmgRange.high = 5;
        weapons.push_back(wep);
        break;
    case 3: // Cleric
        className = "Cleric";
        accuracy = 8;
        hitPoints = 15;
        maxHitPoints = 15;
        expPoints = 0;
        nextLevelExp = 1000;
        level = 1;
        armor = 5;
        wep.weaponName = "Flail";
        wep.dmgRange.low = 1;
        wep.dmgRange.high = 6;
        weapons.push_back(wep);
        break;
    default: // Thief
        className = "Thief";
        accuracy = 7;
        hitPoints = 12;
        maxHitPoints = 12;
        expPoints = 0;
        nextLevelExp = 1000;
        level = 1;
        armor = 5;
        wep.weaponName = "Short Sword";
        wep.dmgRange.low = 2;
        wep.dmgRange.high = 6;
        weapons.push_back(wep);
        break;
    }
    
    cout << "Select your Race"<< endl;
    cout << endl;
    cout << "Humans get + 4 armor" << endl << "Elfs get + 3 accuracy"
    << endl << "Dwarfs get + 5 hitpoints " << endl << endl;
    cout << "1)Elf 2)Dawrf 3)Human: ";

    int raceNum;
    cin >> raceNum;

    switch (raceNum) {
        case 1:
            race.raceName = "Elf";
            accuracy += 3;
            break;
        case 2:
            race.raceName = "Dawrf";
            hitPoints += 5;
        case 3:
            race.raceName = "Human";
            armor += 4;
        default:

            break;
    }
    
}

bool Player::attack(Monster& monster)
{
    int selection = 0;
    cout << "1) Attack 2) Run 3) Inventory: ";
    cin >> selection;
    cout << endl;
    
    switch (selection) {
    case 1:
        cout << "You attack the " << monster.getName() << " with your migthy "
            << weapon.weaponName << endl;
        if(Random(0, 10) < accuracy){
            float critDmg = 1.5;
            int critChance = Random(1,3);
            int damage;
            int totalDamage;
            if(critChance == 2){
                damage = Random(weapon.dmgRange) * critDmg;
                totalDamage = damage - monster.getArmor();
            }
            else{
                damage = Random(weapon.dmgRange);
                totalDamage = damage - monster.getArmor();
            }
            
            
            if(totalDamage <= 0){
                cout <<"You failed to penetrate the monsters armor." << endl;
            }
            else{
                if(damage > weapon.dmgRange.high){
                    cout <<"CRITICAL HIT!: " << damage << endl;
                    cout <<"His body shivers with terror!" << endl;
                    monster.takeDamage(damage);
                }
                else{
                    cout << "You attack for a " << totalDamage <<" !" << endl;
                    monster.takeDamage(totalDamage);
                }

            }
        }
        else{
            cout << "You miss!" << endl;
        }
        cout << endl;
        break;
            
    case 3:
        pickWeapon(weapons);
        break;
            
    case 2:
        int roll = Random(1,4);
        if(roll == 1){
            cout << "You ran away like a coward! " << endl;
            return true;
        }
        else{
            cout << "Pick up your weapon and fight!" << endl;
        }
        break;
    }
    
    return false;
}

void Player::levelUp(){
    if(expPoints >= nextLevelExp){
        cout << "Level up!" << endl;
        level++;
        nextLevelExp = level * level * 1000;
        
        if(race.raceName == "Elf"){
            accuracy += Random(1, 3);
            maxHitPoints += Random(2, 4);
            armor += Random(1, 2);
        }
        else if(race.raceName == "Dawrf"){
            accuracy += Random(1, 2);
            maxHitPoints += Random(2, 5);
            armor += Random(1, 2);
        }
        else{
            accuracy += Random(1, 2);
            maxHitPoints += Random(2, 4);
            armor += Random(1, 4);
        }
        //add the attributes
        
        
        hitPoints = maxHitPoints;
    }

}

void Player::rest(){
    int restAttack = Random(1, 5);
    if(restAttack == 1){
        isResting = true;
    }
    else{
        cout <<"Rest your bones young one" << endl;
        hitPoints = maxHitPoints;
    }
    
}

void Player::viewStats(){
    cout << "PLAYER STATS" << endl;
    cout << "============" << endl;
    cout << endl;
    cout << "Level: " << level << endl;
    cout << "Name: " << name << endl;
    cout << "Class: " << className << endl;
    cout << "Race: " << race.raceName << endl;
    cout << "Accuarcy :" << accuracy << endl;
    cout << "Hit points: " << hitPoints << endl;
    cout << "Max hit Points: " << maxHitPoints << endl;
    cout << "xp: " << expPoints << endl;
    cout << "xp for next lvl: " << nextLevelExp << endl;
    cout << "Weapon Name = " << weapon.weaponName << endl;
    cout << "Weapon Damage = " << weapon.dmgRange.low << "-" << weapon.dmgRange.high << endl;
    cout << "Gold = " << gold << endl;
    cout << endl;
    cout << "END PLAYER STATS" << endl;
    cout << "================" << endl;
    cout << endl;

}

void Player::victory(int xp, int goldDrop){
    cout << "You won the battle!" << endl;
    cout << "You win " << xp
    << " experience points!" << endl;
    expPoints += xp;
    nextLevelExp -= xp;
    cout << "Gold reward " << goldDrop << endl;
    
    gold += goldDrop;
}

void Player::gameover()
{
    cout << "You died in battle..." << endl;
    cout << endl;
    cout << "================================" << endl;
    cout << "GAME OVER!" << endl;
    cout << "================================" << endl;
    cout << "Press 'q' to quit: ";
    char q = 'q';
    cin >> q;
    cout << endl; 
}
void Player::displayHitPoints(){
    cout << name << "'s hitpoints = " << hitPoints << endl;
}

void Player::pickWeapon(vector<Weapon>& v){
    int invpos = 0;
    for(vector<Weapon>::const_iterator i = weapons.begin(); i != weapons.end(); ++i, invpos++){
        cout << invpos << ": ";
        cout << v.at(invpos);

    }
    cout << "Pick another weapon" << endl;
    int invNumber;
    cin >> invNumber;
    invpos = 0;
    for(vector<Weapon>::const_iterator i = weapons.begin(); i != weapons.end(); ++i, invpos++){
        if(invNumber == invpos){
            weapon.weaponName = v.at(invpos).weaponName;
            weapon.dmgRange.low = v.at(invpos).dmgRange.low;
            weapon.dmgRange.high = v.at(invpos).dmgRange.high;
        }
    }


    
}



