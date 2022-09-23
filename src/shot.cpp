#include "shot.h"
#include <cmath>
#include <iostream>



void Shot::Update() {
  switch (direction) {
    case Direction::kUp:
      pos_y -= 1;
      break;

    case Direction::kDown:
      pos_y += 1;
      break;

    case Direction::kLeft:
      pos_x -= 1;
      break;

    case Direction::kRight:
      pos_x += 1;
      break;
  }
}