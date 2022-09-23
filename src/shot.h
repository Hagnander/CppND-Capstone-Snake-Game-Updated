#ifndef SHOT_H
#define SHOT_H

#include <vector>
#include "SDL.h"

class Shot {
 public:
 enum class Direction { kUp, kDown, kLeft, kRight };
 void Update(); 
  
 Direction direction = Direction::kUp; 
 float pos_x;
 float pos_y;
 private:
  
};

#endif