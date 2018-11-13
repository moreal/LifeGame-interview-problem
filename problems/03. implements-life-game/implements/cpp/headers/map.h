#include "unit.h"

#include <functional>
#include <iostream>

namespace loadcomplete {
    template <const int HEIGHT, const int WIDTH>
    class Map {
     public:
        void MoveToNextGeneration();
        void ChangeGeneration();
        void GrowAllUnits();
        void CheckAllUnits();

        bool HasLivingUnit();

        Unit& GetUnit(const int, const int);
    
        Unit (*GetUnitsFromNow())[WIDTH];
        Unit (*GetUnitsFromNextGeneration())[WIDTH];
     
     private:
        enum class EnumForNowBuffer : uint8_t {
            BUFFER_A,
            BUFFER_B,
        } now_buffer;


        const int GetUnitsCountFromPoint(const int, const int);
        const int ExistsUnit(const int, const int);

        void FillUnitsDataWithValue(Unit (*units)[WIDTH], int age);

        void ForEachUnits(Unit (*units)[WIDTH], std::function<void(Unit&)> fn);

        Unit units_buffer_a[HEIGHT][WIDTH] {};
        Unit units_buffer_b[HEIGHT][WIDTH] {};
    };

    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::GrowAllUnits() {
        ForEachUnits(GetUnitsFromNow(), [](Unit& unit){
            unit.GrowOld();
        });
    }


    template<const int HEIGHT, const int WIDTH>
    Unit (*Map<HEIGHT, WIDTH>::GetUnitsFromNow()) [WIDTH] {
        return now_buffer == EnumForNowBuffer::BUFFER_A ? units_buffer_a : units_buffer_b;
    }
    

    template<const int HEIGHT, const int WIDTH>
    Unit (* Map<HEIGHT, WIDTH>::GetUnitsFromNextGeneration()) [WIDTH] {
        return now_buffer == EnumForNowBuffer::BUFFER_A ? units_buffer_b : units_buffer_a;
    }


    template<const int HEIGHT, const int WIDTH>
    Unit& Map<HEIGHT, WIDTH>::GetUnit(const int x, const int y) {
        return GetUnitsFromNow()[y][x];
    }


    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::CheckAllUnits() {
        ForEachUnits(GetUnitsFromNow(), [](Unit& unit) {
            unit.CheckAndKill();
        });
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
                if (GetUnitsFromNow()[i][j].IsLive())
                    return true;
            }
        }
        return false;
    }

    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::MoveToNextGeneration() {
        auto now_units = GetUnitsFromNow();
        auto next_units = GetUnitsFromNextGeneration();

        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                const int count = GetUnitsCountFromPoint(j, i); 
                if (count == 3) {
                    if (GetUnit(i, j).IsLive()) {
                        next_units[j][i] = GetUnit(i, j);
                    } else {
                        GetUnit(i, j).GiveBirth();
                    }
                } else if (count == 2) {
                    if (GetUnit(i, j).IsLive()) {
                        next_units[j][i] = GetUnit(i, j);
                    }
                } else {
                    GetUnit(i, j).SetAge(Unit::DEATH);
                }
            }
        }
    }

    template<const int HEIGHT, const int WIDTH>
    const int Map<HEIGHT, WIDTH>::GetUnitsCountFromPoint(const int x, const int y) {
        return ExistsUnit(x - 1, y - 1) + ExistsUnit(x, y - 1) + ExistsUnit(x + 1, y - 1)
             + ExistsUnit(x - 1, y)                            + ExistsUnit(x + 1, y)
             + ExistsUnit(x - 1, y + 1) + ExistsUnit(x, y + 1) + ExistsUnit(x + 1,  y + 1);
    }


    template<const int HEIGHT, const int WIDTH>
    const int Map<HEIGHT, WIDTH>::ExistsUnit(const int x, const int y) {
        if (x < 0 || x >= WIDTH) return 0;
        else if (y < 0 || y >= HEIGHT) return 0;
        else return GetUnit(x, y).IsLive() == true;
    }


    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::ForEachUnits(Unit (*units)[WIDTH], std::function<void(Unit&)> fn) {
        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                fn(units[i][j]);
            }
        }
    }

    
    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::FillUnitsDataWithValue(Unit (*units)[WIDTH], int age) {
        ForEachUnits(units, [age](Unit& unit) {
            unit.SetAge(age);
        });
    }
}