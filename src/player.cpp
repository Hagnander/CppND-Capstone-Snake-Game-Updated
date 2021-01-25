#include <string>
#include <iostream>

#include "player.h"

using std::string;

void Player::Name(std::string name)
{
    _name = name;
}

bool Compare(Player p1, Player p2){
    return p1.Score()>p2.Score();
};