//
//  Random.cpp
//  kafli5.Rpg
//
//  Created by Sigursteinn Bjarni on 04/10/14.
//  Copyright (c) 2014 Sigursteinn Bjarni. All rights reserved.
//

#include "Random.h"

#include <cstdlib>

int Random(Range r)
{
    return r.low + rand() % ((r.high + 1) - r.low);
}
// Returns a random number in [low, high].
int Random(int low, int high)
{
    return low + rand() % ((high + 1) - low);
}