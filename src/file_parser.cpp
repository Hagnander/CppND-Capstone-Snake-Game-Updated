#include <vector>
#include <string>
#include <sstream>  
#include <iostream>

#include "file_parser.h"




using std::string;
using std::vector;

void FileParser::ParseFile()
{
    string Name, Score, line;
    std::ifstream stream("../src/HighScore.txt");
    if (stream.is_open())
    {
        while (std::getline(stream, line))
        {
            std::istringstream linestream(line);
            while (linestream >> Name >> Score)
            {
                _names.push_back(Name);
                _scores.push_back(Score);
            }
        }
    }
}
