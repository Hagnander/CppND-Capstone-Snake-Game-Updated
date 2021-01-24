#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <fstream>
#include <vector>
#include <string>

#include "player.h"

class FileParser{
    public:
        void ParseFile();
        int GetPersonalBestRank(std::string name);
        int UpdateHighScoreList(std::string name, int score);
    private:
        std::vector<Player> _list;
};

#endif