#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "file_parser.h"
#include "player.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  //Open a file to get list of highscores
  FileParser fileparser;
  fileparser.ParseFile();
  //Get name from player
  Player player;
  std::cout << "Welcome to Snake, What's your name? \n";
  std::string name = "nobody";
  std::cin >> name;
  player.Name(name);
  bool ContinuePlaying = true;
  while (ContinuePlaying == true)
  {
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    //Update High Score list and return rank (save 100 values in high score list)
    int Rank = fileparser.UpdateHighScoreList(player.Name(),game.GetScore());
    //Write to file
    fileparser.WriteFile();
    int PersonalBestRank = fileparser.GetPersonalBestRank(player.Name());
    //Inform the player about best postion in high score list
    if (Rank == PersonalBestRank)
      std::cout << "Congrats " << player.Name() << "! you set a new personal record and reached pos = " << Rank << " on High-score Table \n";
    else if (Rank <= kMaxEntries)
      std::cout << "Congrats " << player.Name() << "! you reached pos = " << Rank << " on High-score Table \n";
    else
      std::cout << "You did not reach the High-score Table \n";
  
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    fileparser.PrintTop5();
    std::string PlayAgain;
    std::cout << "If you want to play again type y and hit enter \n";
    std::cin >> PlayAgain;
    if (PlayAgain != "y")
      ContinuePlaying = false;
  }
  return 0;
}