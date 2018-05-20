//==========================================================================================
// Contains functions of the Player class
#include <iostream>
#include <ctime>
#include "player.h"
#include <chrono>
#include <sstream>

using namespace std;



//
// ...
string Player::getName() {
    return player_name;
}

//
// ...
Player::Player(const string& name)
{
    player_name = name;
    altClues = 0;
}

//
// ...
int Player::getAlternativeClues() {
    return Player::altClues;
}



//
// ...
void Player::printStartTime() {

}


//
// ...
void Player::printEndTime() {
}


//
// ...
void Player::printElapsedInSeconds() {

    cout << elapsedTime << "s";
}

