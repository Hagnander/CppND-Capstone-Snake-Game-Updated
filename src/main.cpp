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
    std::cout << "Congratulations! " << player.Name() << " you have a new personal record and reached position = " << Rank << " on Highscore List \n";
  else if (Rank <= kMaxEntries)
    std::cout << "Congratulations! " << player.Name() << " you reached position = " << Rank << " on Highscore List \n";
  else
    std::cout << "You did not reach the Highscore List \n";
  
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  fileparser.PrintTop5();
  

  return 0;
}