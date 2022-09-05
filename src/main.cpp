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
  Player player1, player2;
  std::cout << "Welcome to Snake, What's your name? \n";
  std::string name1 = "nobody";
  std::cin >> name1;
  player1.Name(name1);
  std::cout << "Welcome to Snake, What's your name? \n";
  std::string name2 = "nobody";
  std::cin >> name2;
  player2.Name(name2);
  bool ContinuePlaying = true;
  while (ContinuePlaying == true)
  {
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    //Update High Score list and return rank (save 100 values in high score list)
    int RankPlayer1 = fileparser.UpdateHighScoreList(player1.Name(),game.GetScore1());
    int RankPlayer2 = fileparser.UpdateHighScoreList(player2.Name(),game.GetScore2());
    //Write to file
    fileparser.WriteFile();
    int PersonalBestRank = fileparser.GetPersonalBestRank(player1.Name());
    //Inform the player about best postion in high score list
    if (RankPlayer1 == PersonalBestRank)
      std::cout << "Congrats " << player1.Name() << "! you set a new personal record and reached pos = " << RankPlayer1 << " on High-score Table \n";
    else if (RankPlayer1 <= kMaxEntries)
      std::cout << "Congrats " << player1.Name() << "! you reached pos = " << RankPlayer1 << " on High-score Table \n";
    else
      std::cout << player1.Name() << " did not reach the High-score Table \n";

    PersonalBestRank = fileparser.GetPersonalBestRank(player2.Name());
    //Inform the player about best postion in high score list
    if (RankPlayer2 == PersonalBestRank)
      std::cout << "Congrats " << player2.Name() << "! you set a new personal record and reached pos = " << RankPlayer2 << " on High-score Table \n";
    else if (RankPlayer2 <= kMaxEntries)
      std::cout << "Congrats " << player2.Name() << "! you reached pos = " << RankPlayer2 << " on High-score Table \n";
    else
      std::cout << player2.Name() << " did not reach the High-score Table \n";
    
  
    std::cout << player1.Name() << " Score: " << game.GetScore1() << "\n";
    std::cout << player1.Name() << " Size: " << game.GetSize() << "\n";
    std::cout << player2.Name() << " Score: " << game.GetScore2() << "\n";
    std::cout << player2.Name() << " Size: " << game.GetSize() << "\n";
    fileparser.PrintTop5();
    std::string PlayAgain;
    std::cout << "If you want to play again type y and hit enter \n";
    std::cin >> PlayAgain;
    if (PlayAgain != "y")
      ContinuePlaying = false;
  }
  return 0;
}