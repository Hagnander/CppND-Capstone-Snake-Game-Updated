# Snake Game

This is my Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Project Structure
### Execution
Before starting the game loop the user is ask to enter his/her name and a High-score table is read. Objects of Player, Controller, Game and Renderer are initialized. 
The game loop runs continuously during gameplay. Each turn of the loop, it processes user input, updates the game state, and renders the game. It tracks the passage of time to control the rate of gameplay.
At game over the score is compared with the High-score table and the user is informed about the results. The High-score table is saved to file.


### Classes
class Controller: Handles the user input.
class FileParser: Read and write to the HighScore.txt and handles the High-score table in the game. The High-score table is a vector of the class Player.
class Game: Handles the state in the game.
class Player: Has the attributes _name and _score for a game session.
class Renderer: Does the call to the SDL library for rendering.
class Snake: Responsible for the behaviour of the snake, such as motion and growing (when eating food).

### Folders/Files
Besides .cpp files and .h files that matches the classes above and a main.cpp, there is a HighScore.txt with the High-score table. 

## Addressed rubric points for the project
The following criteria are addressed:
### Loops, Functions, I/O
The project demonstrates an understanding of C++ functions and control structures.
The project reads data from a file and process the data, or the program writes data to a file.
The project accepts user input and processes the input.
### Object Oriented Programming
The project uses Object Oriented Programming techniques.
Classes use appropriate access specifiers for class members.
Classes abstract implementation details from their interfaces.
Classes encapsulate behavior.
### Memory Management
-
### Concurrency
-

## Fix/Feature
Fix: Corrected bug in starter project from Udacity. Food could be placed outside the grid in the game.
Feature: The game has a High-score table and the user enter his/her name before start of game.
Feature: There is a frame surronding the game grid and the player must keep the snake within the frame.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.