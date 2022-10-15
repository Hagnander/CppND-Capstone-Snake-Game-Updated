#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include "shot.h"


void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::Fire(Snake &snake, Shot &bullet) const {
  //If snake does not have an active shot, create one
  if (snake.shotActive==false) {
    //Set start position and direction of the bullet
    bullet.pos_x = snake.head_x;
    bullet.pos_y = snake.head_y;
    bullet.direction = snake.direction;
    snake.shotActive = true;
  } 
}  


void Controller::HandleSnakeInput(bool &running, Snake &snake, Snake &snake2, Shot &bullet1,
  Shot &bullet2) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;
        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;
        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;
        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
        case SDLK_w:
          ChangeDirection(snake2, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;
        case SDLK_s:
          ChangeDirection(snake2, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;
        case SDLK_a:
          ChangeDirection(snake2, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;
        case SDLK_d:
          ChangeDirection(snake2, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;  
        case SDLK_SPACE:
          Fire(snake, bullet1);
          break;    
      }
    }
  }
}