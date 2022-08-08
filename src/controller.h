#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller 
{
    public:
        void HandleSnakeInput(bool &running, Snake &snake) const;
        void HandleSnake2Input(bool &running, Snake &snake) const;

    private:
        void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif