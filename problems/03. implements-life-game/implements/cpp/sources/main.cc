#include "lifegame.h"

#include <iostream>

auto main() -> int {
    using loadcomplete::LifeGame;

    LifeGame<25, 25> lifeGame;
    
    lifeGame.StartGame();
    
    return 0;
}