#include "map.hpp"

namespace loadcomplete {
    template <const int HEIGHT, const int WIDTH>
    class LifeGame {
     public:
        void InitializeMapByInput();
        void InitializeMapWithArguments();

        void ProcessLifeGame();

     private:
        Map<HEIGHT, WIDTH> map;
    };
}