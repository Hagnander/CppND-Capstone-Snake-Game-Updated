#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height, 1),
      snake2(grid_width, grid_height, -1),
      engine(dev()),
      random_w(1, static_cast<int>(grid_width -2)), //The food must be within the frame
      random_h(1, static_cast<int>(grid_height -2)) {
  PlaceFood();
  _grid_height = grid_height;
  _grid_width = grid_width;
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    
    //controller.HandleSnake2Input(running, snake2);
    controller.HandleSnakeInput(running, snake, snake2, bullet1, bullet2);
    Update();
    renderer.Render(snake, snake2, bullet1, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score1, score2, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y) && !snake2.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive && !snake2.alive) return;
  
  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  int new2_x = static_cast<int>(snake2.head_x);
  int new2_y = static_cast<int>(snake2.head_y);
  
  if (snake.alive)
  {
     snake.Update();
     
     new_x = static_cast<int>(snake.head_x);
     new_y = static_cast<int>(snake.head_y);
     //Check boundaries
     //If snake head  hit the frame, the game ends
     if ((new_x == _grid_width - 1) || (new_x == 0) || (new_y == _grid_height - 1) || (new_y == 0)){
        snake.alive = false;
        return;
     }
  
     // Check if there's food over here
     if (food.x == new_x && food.y == new_y) {
        score1++;
        PlaceFood();
        // Grow snake and increase speed.
        snake.GrowBody();
        snake.speed += 0.02;
     }
  }
  if (snake2.alive)
  {
      snake2.Update();
      new2_x = static_cast<int>(snake2.head_x);
      new2_y = static_cast<int>(snake2.head_y);
      //Check boundaries
      //If snake head  hit the frame, the game ends
      if ((new2_x == _grid_width - 1) || (new2_x == 0) || (new2_y == _grid_height - 1) || (new2_y == 0)){
         snake2.alive = false;
         return;
      }
  
      // Check if there's food over here
      if (food.x == new2_x && food.y == new2_y) {
         score2++;
         PlaceFood();
         // Grow snake and increase speed.
         snake2.GrowBody();
         snake2.speed += 0.02;
      }
  }
  // JH gör om så att du har en vector med bullets och iterera 
  // Update the position of the bullet
  if (snake.shotActive) {
    bullet1.Update();
  }
  if (snake2.shotActive) {
    bullet2.Update();
  }

  //Check if any snake is shot 
  //Check if we have a head to head collision between the snakes
  if (new_x == new2_x && new_y == new2_y) {
    score1=score1+100;
    snake.alive = false;
    snake2.alive = false;
    return;
  }
}

int Game::GetScore1() const { return score1; }
int Game::GetScore2() const { return score2; }
int Game::GetSize() const { return snake.size; }
int Game::GetSize2() const { return snake2.size; }