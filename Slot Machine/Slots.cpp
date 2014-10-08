#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int Random(int low, int high);

int main(int argc, const char * argv[])
{
    // Variables
    srand((unsigned) time(NULL));
    int balance = 1000;
    int choice;
    int bet;
    // gameloop
    while (choice != 2) {
        cout << "Players chips: " << balance << endl;
        cout << "1) Play slot. 2) Exit." << endl;
        cin >> choice;
    
        if(choice == 1){
            // a loop to check input
            do{
                cout <<"Place your bet: ";
                cin >> bet;
                if(bet > balance || bet <= 0){
                    cout <<"Not a valid bet" << endl;
                }
            }while (balance < bet || bet <= 0);

            int number1 = Random(2, 7);
            int number2 = Random(2, 7);
            int number3 = Random(2, 7);
            cout << number1 << " " << number2 << " " << number3 << endl;
            
            if(number1 == 7 && number2 == 7 && number3 == 7){
                cout <<"Jackpot! You win " << bet * 10 << endl;
                bet = bet * 10;
                balance += bet;
            }
            else if (number1 == number2 && number1 == number3 && number2 == number3 && number1 != 7  && number2 != 7 && number3 != 7)
                {
                cout <<"Hat trick! You win " << bet * 5 << endl;
                    bet = bet * 5;
                balance += bet;
            }
            
            else if(number1 == number2 || number1 == number3 || number2 == number3){
                cout <<"A duce! You win " <<bet * 3 << endl;
                bet = bet * 3;
                balance += bet;
            }
            else{
                cout << "You lose..." << endl;
                balance = balance - bet;
            }
        }
        else if (choice == 2){
            cout << "Exiting...." << endl;
        }
        if (balance <= 0){
            cout << "You have lost all of your money you fool" << endl;
            exit(0);
        }
    }
    
    return 0;
}

int Random(int low, int high)
{
    int number = rand()%((high - low )+ 1) + low;
    return number;
}

