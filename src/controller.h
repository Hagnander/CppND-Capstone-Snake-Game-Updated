#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "shot.h"

class Controller 
{
    public:
        void HandleSnakeInput(bool &running, Snake &snake, Snake &snake2, Shot &bullet1,
  Shot &bullet2) const;

    private:
        void Fire(Snake &snake, Shot &bullet) const ;
        void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif