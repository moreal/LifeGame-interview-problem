#include "map.h"

namespace loadcomplete {
    template <const int HEIGHT, const int WIDTH>
    class LifeGame {
     public:
        void start_game();
        void show_map();

     private:
        void initialize_map_by_input();
        void process_life_of_units();
        
        Map<HEIGHT, WIDTH> map;
    };

    template <const int HEIGHT, const int WIDTH>
    void LifeGame<HEIGHT, WIDTH>::initialize_map_by_input() {
        int age;

        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                std::cin >> age;
                map.get_unit(i, j).set_age(age == 0 ? -1 : age);
            }
        }
    }


    template <const int HEIGHT, const int WIDTH>
    void LifeGame<HEIGHT, WIDTH>::process_life_of_units() {
        map.move_to_next_generation();
        map.change_generation();
        map.grow_all_units();
        map.check_all_units();
    }

    template <const int HEIGHT, const int WIDTH>
    void LifeGame<HEIGHT, WIDTH>::start_game() {
        initialize_map_by_input();
        while (map.has_living_unit()) {
            map.show_map();
            process_life_of_units();
        }
    }
}