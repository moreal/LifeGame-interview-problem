#include "lifegame.h"

#include <iostream>

auto main() -> int {
    using loadcomplete::LifeGame;

    LifeGame<25, 25> lifeGame;
    
    lifeGame.start_game();
    
    return 0;
}