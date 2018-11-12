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
    Unit (** Map<HEIGHT, WIDTH>::GetNextUnitsBuffer())[HEIGHT][WIDTH] {
        return now_buffer == EnumForNowBuffer::BUFFER_A ? units_buffer_b : units_buffer_a;
    }


    template<const int HEIGHT, const int WIDTH>
    Unit& Map<HEIGHT, WIDTH>::GetUnit(const int x, const int y) {
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

    
    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::ChangeGeneration() {
        if (now_buffer == EnumForNowBuffer::BUFFER_A) {
            now_buffer = EnumForNowBuffer::BUFFER_B;
        } else {
            now_buffer = EnumForNowBuffer::BUFFER_A;
        }
    }


    template<const int HEIGHT, const int WIDTH>
    bool Map<HEIGHT, WIDTH>::HasLivingUnit() {
        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                if (GetUnits()[i][j].IsLive())
                    return true;
            }
        }
        return false;
    }

    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::MoveToNextGeneration() {
        auto now_units = GetUnits();
        auto next_units = GetNextUnitsBuffer();

        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                
            }
        }

        ChangeGeneration();
    }

    template<const int HEIGHT, const int WIDTH>
    const int Map<HEIGHT, WIDTH>::GetUnitsCountFromPoint(const int x, const int y) const {
        return ExistsUnit(x - 1, y - 1) + ExistsUnit(x - 1, y) + ExistsUnit(x - 1, y + 1)
            + ExistsUnit(x, y - 1) + ExistsUnit()
    }

    template<const int HEIGHT, const int WIDTH>
    const int Map<HEIGHT, WIDTH>::ExistsUnit(const int x, const int y) const {
        if (x < 0 || x >= WIDTH) return 0;
        else if (y < 0 || y >= HEIGHT) return 0;
        else return GetUnit(x, y).IsLive() == true;
    }
}