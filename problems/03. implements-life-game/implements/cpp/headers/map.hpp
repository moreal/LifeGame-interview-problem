#include "unit.hpp"

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
    
     private:
        enum class EnumForNowBuffer : uint8_t {
            BUFFER_A,
            BUFFER_B,
        } now_buffer;

        Unit (**GetUnits())[HEIGHT][WIDTH];
        Unit (**GetNextUnitsBuffer())[HEIGHT][WIDTH];

        const int GetUnitsCountFromPoint(const int, const int) const;
        const int ExistsUnit(const int, const int) const;

        Unit units_buffer_a[HEIGHT][WIDTH] {};
        Unit units_buffer_b[HEIGHT][WIDTH] {};
    };
}