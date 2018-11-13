#include "unit.h"

namespace loadcomplete {
    Unit::Unit() : age(DEATH) {
        
    }

    void Unit::SetAge(uint8_t value) {
        age = value;
    }

    uint8_t Unit::GetAge() const {
        return age;
    }

    void Unit::GiveBirth() {
        if (!IsLive()) {
            age = NEWBORN;
        }
    }

    void Unit::GrowOld() {
        if (IsLive()) {
            age += 1;
        }
    }

    bool Unit::IsLive() const {
        return age != DEATH;
    }

    void Unit::CheckAndKill() {
        if (!IsLive()) {
            age = DEATH;
        }
    }
}