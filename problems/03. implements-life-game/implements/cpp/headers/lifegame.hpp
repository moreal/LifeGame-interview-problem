#include "map.hpp"

namespace loadcomplete {
    template <const int HEIGHT, const int WIDTH>
    class LifeGame {
     public:
        void StartGame();

     private:
        void InitializeMapByInput();
        void ProcessLifeOfUnits();
        
        Map<HEIGHT, WIDTH> map;
    };
}