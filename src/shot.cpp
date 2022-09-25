#include "shot.h"
#include <cmath>
#include <iostream>


//Make speed of bullet dependent on snake speed
void Shot::Update() {
  switch (direction) {
    case Direction::kUp:
      pos_y -= 0.5;
      break;

    case Direction::kDown:
      pos_y += 0.5;
      break;

    case Direction::kLeft:
      pos_x -= 0.5;
      break;

    case Direction::kRight:
      pos_x += 0.5;
      break;
  }
}