#include "unit.hpp"

namespace loadcomplete {
    void Unit::SetAge(uint8_t value) {
        age = value;
    }

    uint8_t Unit::GetAge() const {
        return age;
    }

    void Unit::GiveBirth() {
        if (!IsLive()) {
            age = 1;
        }
    }

    void Unit::GrowOld() {
        if (IsLive()) {
            age += 1;
        }
    }

    bool Unit::IsLive() const {
        return 0 < age && age < 7;
    }

    void Unit::CheckAndKill() {
        if (!IsLive()) {
            age = 0;
        }
    }
}