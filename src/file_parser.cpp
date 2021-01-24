#include <vector>
#include <string>
#include <sstream>  
#include <iostream>
#include <algorithm>

#include "file_parser.h"
#include "player.h"

using std::string;
using std::vector;

void FileParser::ParseFile()
{
    string Name, Score, line;
    Player player;
    std::ifstream stream("../src/HighScore.txt");
    if (stream.is_open())
    {
        while (std::getline(stream, line))
        {
            std::istringstream linestream(line);
            while (linestream >> Name >> Score)
            {
                player.Name(Name);
                player.Score(std::stoi(Score));
                _list.push_back(player);
            }
        }
    }
}

int FileParser::UpdateHighScoreList(std::string name, int score)
{
    Player player;
    player.Name(name);
    player.Score(score);
    if ((_list.back().Score() < score) || _list.size() <= 100)//kNumberOfEnries
    {
        _list.push_back(player);
        std::sort(_list.begin(), _list.end(), Compare);
        //Find the index with the score and return that index
        int i = 0; //We start to count on 1 in highscore list
        for (std::vector<Player>::iterator it = _list.begin() ; it != _list.end(); ++it)
        {
            i++;
            if (it->Score() == score)
                return i;
        }
    }
    return 10000;//kDidNotReachList;
}
 
int FileParser::GetPersonalBestRank(std::string name)
{
    int i = 0; 
    for (std::vector<Player>::iterator it = _list.begin() ; it != _list.end(); ++it)
    {
        i++;//We start to count on 1 in highscore list
        if (it->Name() == name)
            return i;
    }
    return 500;
}

void FileParser::PrintTop5(void)
{
    int i = 0;
    std::cout << "Highscore List Top 5 \n";
    for (std::vector<Player>::iterator it = _list.begin() ; it < _list.begin() + 5; ++it)
    {
        i++;
        std::cout << "Rank" << i <<": \t" << it->Name() << "\t" << it->Score() <<"\n";
    }
}
;
