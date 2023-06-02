#include <iostream>
#include <cstdlib>
#include "libThree.h"

using namespace std;
using namespace ShipSpace;

int main ()
{
    srand(time(0));
    int intSeaArr[SEA_LEVEL];
    
    InitialGame(intSeaArr);
    
    char chInput = '\0';
    int FuelLevel = 20;
    bool blnContinue = true;
    bool blnGameOver = false;
    
    do
    {
        
        system("clear");
        cout << "Your fuel level is: " << FuelLevel << endl << endl;
        DisplayGame(intSeaArr);
        cin >> chInput;
        
        switch(chInput)
        {
            case 'D':
            case 'd':
            {
                MoveShip(MOVE_RIGHT, intSeaArr, FuelLevel);
                break;
            }
            case 'A':
            case 'a':
            {
                MoveShip(MOVE_LEFT, intSeaArr, FuelLevel);
                break;
            }
            case 'Q':
            case 'q':
            {
                blnContinue = false;
                break;
            }
            default:
            {
                cerr << "Please enter a valid option." << endl;
                pause();
            }
        }
        
       blnGameOver = GameOver(FuelLevel, intSeaArr);
       
       if (blnGameOver)
            blnContinue = false;
        
        
    }while(blnContinue);
    
    pause();
    
    system("clear");
    
    if(blnGameOver)
    {
        cout << "**************************************************************" << endl
            << "*          Congratulations you did it won the game            *" << endl
            << "**************************************************************" << endl;
    }
    else
    {
        cout << "**************************************************************" << endl
            << "*                 Nobody dont likes quitters!                 *" << endl
            << "**************************************************************" << endl;
    }
    
    
    return 0;
}