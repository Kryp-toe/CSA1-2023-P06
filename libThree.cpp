#include <iostream>
#include <cstdlib>
#include "libThree.h"

using namespace std;

namespace ShipSpace
{
        int GetRand(int Lowest, int Highest)
        {
            int Range = Highest - Lowest +1;
            return (rand()%Range) + Lowest;
        }
        
        void InitialGame(int arr[])
        {
            for(int i=0; i<SEA_LEVEL; i++)
            {
                arr[i] = intSEA;
            }
            
            for(int i=0; i<FUEL_NUM; i++)
            {
                int intFuelLocation = GetRand(0,SEA_LEVEL-1);
                while(intFuelLocation==24)
                {
                    int intFuelLocation = GetRand(0,SEA_LEVEL-1);
                }
                arr[intFuelLocation] = intFUEL;
            }
            
            arr[24] = intSHIP;
        }
        
        void DisplayGame(int arr[])
        {
            
            for(int i=0; i<SEA_LEVEL; i++)
            {
                switch(arr[i])
                {
                    case intSHIP:
                        cout << SHIP;
                        break;
                    case intFUEL:
                        cout << FUEL;
                        break;
                    case intSEA: 
                        cout << SEA;
                        break;
                }
            }
            cout << endl << endl;
            cout << "D: Move Right" << endl;
            cout << "A: Move Left" << endl;
            cout << "Q: Quit" << endl;
        }

        int FindShip(int arr[])
        {
            int intLoc;
            for(int i=0; i<SEA_LEVEL; i++)
            {
                if(arr[i] == intSHIP)
                    intLoc = i;
            }
            return intLoc;
        }
        
        void MoveShip(int Move, int arr[], int &FuelLevel)
        {
            int ShipLocation = FindShip(arr);
            arr[ShipLocation] = intSEA;
            
            switch(Move)
            {
                case MOVE_LEFT:
                {
                    
                    if(intFUEL == arr[ShipLocation-1])
                    {
                        FuelLevel += 5;
                    }
                    else
                    {
                        FuelLevel += (-1);
                    }
                    
                    if(!(ShipLocation == 0))
                    {
                        
                        arr[ShipLocation - 1] = intSHIP;
                        ShipLocation--;
                    }
                    break;
                }
                
                case MOVE_RIGHT:
                {
                    
                    if(intFUEL == arr[ShipLocation+1])
                    {
                        FuelLevel += 5;
                    }
                    else
                    {
                        FuelLevel += (-1);
                    }
                    
                    if(!(ShipLocation == SEA_LEVEL-1))
                    {
                        arr[ShipLocation + 1] = intSHIP;
                        ShipLocation++;
                    }
                    break;
                }
                
                default:
                    cerr << "This shouldnt have happened" << endl;
                    pause();
            }
        }
        
        void pause()
        {
            cin.ignore(100, '\n');
            cout << "Press Enter to continue" << endl;
            cin.get();
        }
        
        bool GameOver(int FuelLevel, int arr[])
        {
            if(FuelLevel == 0)
            {
                return true;
            }
            
            int ShipLocation = FindShip(arr);
            if((ShipLocation == (SEA_LEVEL - 1)) || (ShipLocation == 0))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
}

















