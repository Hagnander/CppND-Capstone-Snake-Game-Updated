#include <fstream>
#include <vector>
#include <string>

class FileParser{
    public:
        void ParseFile();
    private:
        std::vector<std::string> _names;
        std::vector<std::string> _scores;
};