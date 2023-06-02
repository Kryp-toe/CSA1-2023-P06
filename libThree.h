#ifndef LIBTHREE_H_INCLUDED
#define LIBTHREE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SEA_LEVEL = 50;
const int FUEL_NUM = 4;

const int intSEA = 1;
const char SEA = '_';
const int intFUEL = 2;
const char FUEL = '^';
const int intSHIP = 3;
const char SHIP = 'O';

const int MOVE_LEFT = 1;
const int MOVE_RIGHT = 2;

namespace ShipSpace
{
    int GetRand(int Lowest, int Highest);
    void InitialGame(int arr[]);
    void DisplayGame(int arr[]);
    void MoveShip(int Move, int arr[], int &FuelLevel);
    int FindSHip(int arr[]);
    int FindFuel(int arrFuel[], int arrSea[]);
    void pause();
    bool GameOver(int FuelLevel, int arr[]);
}

#endif // LIBTHREE_H_INCLUDED