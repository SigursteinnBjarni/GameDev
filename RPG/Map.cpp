//
//  Map.cpp
//  kafli5.Rpg
//
//  Created by Sigursteinn Bjarni on 06/10/14.
//  Copyright (c) 2014 Sigursteinn Bjarni. All rights reserved.
//

#include "Map.h"
#include "Monster.h"
#include "Random.h"
#include <iostream>
using namespace std;

Map::Map(){
    playerXPos = 0;
    playerYPos = 0;
}

int Map::getPlayerXPos(){
    return playerXPos;
}

int Map::getPlayerYPos(){
    return playerYPos;
}

void Map::movePlayer()
{
    int selection = 1;
    cout << "1) North, 2) East, 3) South, 4) West: ";
    cin >> selection;
    // Update coordinates based on selection.
    switch( selection )
    {
        case 1: // North
            playerYPos++;
            break;
        case 2: // East
            playerXPos++;
            break;
        case 3: // South
            playerYPos--;
            break; 
        default: // West 
           playerXPos--;
            break; 
    } 
    cout << endl; 
}

Monster* Map::checkRandomEncounter()
{
    int roll = Random(0, 20);
    Monster* monster;
    if( roll <= 5 )
    {
        // No encounter, return a null pointer.
        return 0;
    }
    else if(roll >= 6 && roll <= 10)
    {
        monster = new Monster("Orc", 10, 8, 200, 1, "Short Sword", 2, 7, 10);
        cout << "You encountered an Orc!" << endl;
        cout << "Prepare for battle!" << endl;
        cout << endl;
    }
    else if(roll >= 11 && roll <= 15)
    {
        monster = new Monster("Goblin", 6, 6, 100, 0, "Dagger", 1, 5, 5);
        cout << "You encountered a Goblin!" << endl;
        cout << "Prepare for battle!" << endl;
        cout << endl;
    }
    else if(roll >= 16 && roll <= 19)
    {
        monster = new Monster("Ogre", 20, 12, 500, 2, "Club", 3, 8, 15);
        cout << "You encountered an Ogre!" << endl;
        cout << "Prepare for battle!" << endl;
        cout << endl;
    }
    else if(roll == 20)
    { 
        monster = new Monster("Orc Lord", 25, 15, 2000, 5, "Two Handed Sword", 5, 20, 50);
        cout << "You encountered an Orc Lord!!!" << endl;
        cout << "Prepare for battle!" << endl; 
        cout << endl; 
    } 
    return monster;
}

void Map::printPlayerPos()
{
    cout << "Player Position = (" << playerXPos << ", "
    << playerYPos << ")" << endl << endl;
}
