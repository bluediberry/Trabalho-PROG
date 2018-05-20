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
double Player::getElapsedTime() {
    Player::updateEndTime();
    Player::updateElapsedTime();
    return Player::elapsedTime;
}

//
// ...
void Player::updateStartTime() {
    auto startT = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(startT);
    Player::start = start_time;
}

//
// ...
void Player::printStartTime() {

}

//
// ...
void Player::updateEndTime() {
    auto endT = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(endT);
    Player::end = end_time;
}

//
// ...
void Player::printEndTime() {
}

//
// ...
void Player::updateElapsedTime() {
    Player::elapsedTime = (Player::end - Player::start);
}

//
// ...
void Player::incrementAltClues() {
    Player::altClues++;
}

//
// ...
void Player::printElapsedInSeconds() {
    Player::updateEndTime();
    Player::updateElapsedTime();
    cout << Player::elapsedTime << "s";
}

//
// ...
void Player::printAlternativeClues() {

}