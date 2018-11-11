#include "map.hpp"

namespace loadcomplete {
    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::GrowAllUnits() {
        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                GetUnits()[i][j].Grow();
            }
        }
    }

    template<const int HEIGHT, const int WIDTH>
    Unit (** Map<HEIGHT, WIDTH>::GetUnits())[HEIGHT][WIDTH] {
        return now_buffer == EnumForNowBuffer::BUFFER_A ? units_buffer_a : units_buffer_b;
    }


    template<const int HEIGHT, const int WIDTH>
    Unit& Map<HEIGHT, WIDTH>::GetUnit(int x, int y) {
        return GetUnits()[y][x];
    }


    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::CheckAllUnits() {
        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                GetUnits()[i][j].CheckAndKill();
            }
        }
    }
}