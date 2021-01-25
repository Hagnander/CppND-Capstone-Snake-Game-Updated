#ifndef FILE_PLAYER_H
#define FILE_PLAYER_H

#include <string>

class Player
{
    public:
        void Name(std::string name);
        std::string Name() {return _name;}
        int Score() {return _score;}
        void Score(int score) {_score = score;}
        
    private:
        std::string _name = "NoName";
        int _score = 0;
};

bool Compare(Player p1, Player p2);

#endif