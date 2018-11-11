#include "unit.hpp"

namespace loadcomplete {
    template <const int HEIGHT, const int WIDTH>
    class Map {
     public:
        void GrowAllUnits();
        void CheckAllUnits();

        Unit& GetUnit(int x, int y);
    
     private:
        enum class EnumForNowBuffer : uint8_t {
            BUFFER_A,
            BUFFER_B,
        } now_buffer;

        Unit (**GetUnits())[HEIGHT][WIDTH];

        void ChangeGeneration();

        Unit units_buffer_a[HEIGHT][WIDTH] {};
        Unit units_buffer_b[HEIGHT][WIDTH] {};
    };
}