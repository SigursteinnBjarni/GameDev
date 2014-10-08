//
//  Map.h
//  kafli5.Rpg
//
//  Created by Sigursteinn Bjarni on 06/10/14.
//  Copyright (c) 2014 Sigursteinn Bjarni. All rights reserved.
//

#ifndef __kafli5_Rpg__Map__
#define __kafli5_Rpg__Map__

#include "Weapon.h"
#include "Monster.h"
#include <string>

class Map{

public:
    Map();
    
    int getPlayerXPos();
    int getPlayerYPos();
    void movePlayer();
    Monster* checkRandomEncounter();
    void printPlayerPos();
private:
    // Data members.
    int playerXPos;
    int playerYPos;

};



#endif /* defined(__kafli5_Rpg__Map__) */
