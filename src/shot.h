#ifndef SHOT_H
#define SHOT_H

#include <vector>
#include "SDL.h"
#include "snake.h"

class Shot {
 public:
 //enum class Direction { kUp, kDown, kLeft, kRight };
 void Update(); 
  
 Snake::Direction direction = Snake::Direction::kUp; 
 float pos_x;
 float pos_y;
 private:
  
};

#endif