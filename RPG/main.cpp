
#include <iostream>
#include "Player.h"
#include "Map.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Map gameMap;
Player mainPlayer;
Monster* monster = 0;
bool done = false;

void fight();

int main(int argc, const char * argv[]) {

    srand((unsigned) time(0));
    
    mainPlayer.createClass();
    
    // begin the game loop
   
    
    while (!done) {
        gameMap.printPlayerPos();
        
        int selection = 1;
        cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: ";
        cin >> selection;
        
        
        switch (selection) {
            case 1:
                gameMap.movePlayer();
                fight();
                break;
            case 2:
                mainPlayer.rest();
                if(mainPlayer.isResting == true){
                    cout << "Oh noes you have been ambushed no time for rest! " << endl;
                    fight();
                }
                break;
            case 3:
                mainPlayer.viewStats();
                break; 
            case 4:
                done = true;
                break;
            default:
                break;
        }
    }
    
    return 0;
}

void fight(){
    monster = gameMap.checkRandomEncounter();
    if (monster != 0 ) {
        while (true) {
            mainPlayer.displayHitPoints();
            monster->displayHitPoints(); // notum -> her utaf vid new'um monster
            cout << endl;
            bool runAway = mainPlayer.attack(*monster);
            if( runAway )
                break;
            if( monster->isDead() )
            {
                mainPlayer.victory(monster->getXpReward(), monster->getGoldReward());
                mainPlayer.levelUp();
                break;
            }
            monster->attack(mainPlayer);
            if( mainPlayer.isDead() )
            {
                mainPlayer.gameover();
                done = true;
                break;
            }
            
        }
        // The pointer to a monster returned from
        // checkRandomEncounter was allocated with
        // 'new', so we must delete it to avoid
        // memory leaks.
        delete monster;
        monster = 0;
        }

}
