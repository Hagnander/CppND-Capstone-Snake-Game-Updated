#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <fstream>
#include <vector>
#include <string>

#include "player.h"

const int kMaxEntries = 100; //Max number of entries in Highscore List

class FileParser{
    public:
        void ParseFile(void);
        int GetPersonalBestRank(std::string name);
        int UpdateHighScoreList(std::string name, int score);
        void PrintTop5(void);
        void WriteFile(void);
    private:
        std::vector<Player> _list;
};

#endif