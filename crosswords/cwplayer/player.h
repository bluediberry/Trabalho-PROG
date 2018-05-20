#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Player
{
public:
    string getName();
    Player(const string& name);
    int getAlternativeClues();
    void printStartTime();
    void printEndTime();
    void printElapsedInSeconds();


private:

    string player_name = "";
    time_t start;
    time_t end;
    int altClues = 0;
    double elapsedTime = 0;

};

#endif
