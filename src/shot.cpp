#include "shot.h"
#include <cmath>
#include <iostream>


//Make speed of bullet dependent on snake speed
void Shot::Update() {
  switch (direction) {
    case Snake::Direction::kUp:
      pos_y -= 0.5;
      break;

    case Snake::Direction::kDown:
      pos_y += 0.5;
      break;

    case Snake::Direction::kLeft:
      pos_x -= 0.5;
      break;

    case Snake::Direction::kRight:
      pos_x += 0.5;
      break;
  }
}