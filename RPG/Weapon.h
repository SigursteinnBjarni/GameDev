//
//  Weapon.h
//  kafli5.Rpg
//
//  Created by Sigursteinn Bjarni on 04/10/14.
//  Copyright (c) 2014 Sigursteinn Bjarni. All rights reserved.
//

#ifndef kafli5_Rpg_Weapon_h
#define kafli5_Rpg_Weapon_h
#include "Range.h"
#include <string>
#include <iostream>
using namespace std;
struct Weapon{
    string weaponName;
    Range dmgRange;

    friend ostream& operator <<(ostream& out, const Weapon& wep)
    {
        out << wep.weaponName << " " <<  wep.dmgRange.low << " - " << wep.dmgRange.high << endl;
        return out;
    }
};

#endif
