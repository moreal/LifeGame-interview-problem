#include "unit.h"

namespace loadcomplete {
    Unit::Unit() : age(DEATH) {
        
    }

    void Unit::set_age(int value) {
        age = value;
    }

    int Unit::get_age() const {
        return age;
    }

    void Unit::give_birth() {
        if (!is_live()) {
            age = NEWBORN;
        }
    }

    void Unit::grow_old() {
        if (is_live()) {
            age += 1;
        }
    }

    bool Unit::is_live() const {
        return age != DEATH;
    }

    void Unit::check_and_kill() {
        if (age == TOO_OLD) {
            age = DEATH;
        }
    }
}