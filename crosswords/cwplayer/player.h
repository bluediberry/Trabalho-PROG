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
    double getElapsedTime();
    void incrementAltClues();
    void printAlternativeClues();
    void updateStartTime();
    void printStartTime();
    void updateEndTime();
    void printEndTime();
    void updateElapsedTime();
    void printElapsedInSeconds();


private:

    string player_name = "";
    time_t start;
    time_t end;
    int altClues = 0;
    double elapsedTime = 0;

};

#endif
