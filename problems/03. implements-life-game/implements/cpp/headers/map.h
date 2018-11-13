#include "unit.h"

#include <functional>
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

namespace loadcomplete {
    template <const int HEIGHT, const int WIDTH>
    class Map {
     public:
        void move_to_next_generation();
        void change_generation();
        void grow_all_units();
        void check_all_units();

        bool has_living_unit();

        Unit& get_unit(const int, const int);
        
        void show_map();
        
        enum class NowBuffer : int8_t {
            BUFFER_A,
            BUFFER_B,
        } now_buffer;


     private:
        Unit (*get_units_from_now())[WIDTH];
        Unit (*get_units_from_next_generation())[WIDTH];

        const int get_units_count_from_point(const int, const int);
        const int exists_unit(const int, const int);

        void for_each_units(Unit (*)[WIDTH], std::function<void(Unit&)>);
        void fill_units_data_with_value(Unit (*)[WIDTH], int);

        Unit units_buffer_a[HEIGHT][WIDTH] {};
        Unit units_buffer_b[HEIGHT][WIDTH] {};
    };

    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::grow_all_units() {
        for_each_units(get_units_from_now(), [](Unit& unit){
            unit.grow_old();
        });
    }


    template<const int HEIGHT, const int WIDTH>
    Unit (*Map<HEIGHT, WIDTH>::get_units_from_now()) [WIDTH] {
        return now_buffer == NowBuffer::BUFFER_A ? units_buffer_a : units_buffer_b;
    }
    

    template<const int HEIGHT, const int WIDTH>
    Unit (* Map<HEIGHT, WIDTH>::get_units_from_next_generation()) [WIDTH] {
        return now_buffer == NowBuffer::BUFFER_A ? units_buffer_b : units_buffer_a;
    }


    template<const int HEIGHT, const int WIDTH>
    Unit& Map<HEIGHT, WIDTH>::get_unit(const int y, const int x) {
        return get_units_from_now()[y][x];
    }


    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::check_all_units() {
        for_each_units(get_units_from_now(), [](Unit& unit) {
            unit.check_and_kill();
        });
    }

    
    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::change_generation() {
        if (now_buffer == NowBuffer::BUFFER_A) {
            now_buffer = NowBuffer::BUFFER_B;
        } else {
            now_buffer = NowBuffer::BUFFER_A;
        }
    }


    template<const int HEIGHT, const int WIDTH>
    bool Map<HEIGHT, WIDTH>::has_living_unit() {
        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                if (get_unit(i, j).is_live())
                    return true;
            }
        }
        return false;
    }


    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::show_map() {
        system("clear");

        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                std::cout << (get_unit(i, j).is_live() ? "★" : "☆") << ' ';
            }
            std::putchar('\n');
        }
        std::putchar('\n');

        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }


    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::move_to_next_generation() {
        auto now_units = get_units_from_now();
        auto next_units = get_units_from_next_generation();

        fill_units_data_with_value(next_units, Unit::DEATH);

        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                const int count = get_units_count_from_point(i, j);
                if (count == 3) {
                    if (get_unit(i, j).is_live()) {
                        next_units[i][j] = get_unit(i, j);
                    } else {
                        next_units[i][j].give_birth();
                    }
                } else if (count == 2) {
                    if (get_unit(i, j).is_live()) {
                        next_units[i][j] = get_unit(i, j);
                    }
                }
            }
        }
    }


    template<const int HEIGHT, const int WIDTH>
    const int Map<HEIGHT, WIDTH>::get_units_count_from_point(const int x, const int y) {
        return exists_unit(x - 1, y - 1) + exists_unit(x, y - 1) + exists_unit(x + 1, y - 1)
             + exists_unit(x - 1, y)                             + exists_unit(x + 1, y)
             + exists_unit(x - 1, y + 1) + exists_unit(x, y + 1) + exists_unit(x + 1,  y + 1);
    }


    template<const int HEIGHT, const int WIDTH>
    const int Map<HEIGHT, WIDTH>::exists_unit(const int x, const int y) {
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
            return 0;
        } else {
            return get_unit(x, y).is_live();
        }
    }


    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::for_each_units(Unit (*units)[WIDTH], std::function<void(Unit&)> fn) {
        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                fn(units[i][j]);
            }
        }
    }

    
    template<const int HEIGHT, const int WIDTH>
    void Map<HEIGHT, WIDTH>::fill_units_data_with_value(Unit (*units)[WIDTH], int age) {
        for_each_units(units, [age](Unit& unit) {
            unit.set_age(age);
        });
    }
}