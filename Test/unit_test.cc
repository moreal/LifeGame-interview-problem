#include "gtest/gtest.h"

#include "unit.h"

using loadcomplete::Unit;

TEST(unit_test, constructor_test) {
    Unit unit;
    EXPECT_EQ(unit.get_age(), Unit::DEATH);
}

TEST(unit_test, getter_setter_test) {
    Unit unit;
    unit.set_age(10);
    EXPECT_EQ(unit.get_age(), 10);
}

TEST(unit_test, give_birth_test) {
    Unit unit;
    unit.give_birth();
    EXPECT_EQ(unit.get_age(), Unit::NEWBORN);
}

TEST(unit_test, check_and_kill_test) {
    Unit unit;
    unit.set_age(6);
    unit.grow_old();
    unit.check_and_kill();
    EXPECT_EQ(unit.get_age(), Unit::DEATH);
}

TEST(unit_test, grow_old_test) {
    Unit unit;
    unit.give_birth();
    unit.grow_old();
    EXPECT_EQ(unit.get_age(), 1);
}

TEST(unit_test, is_live_when_birth_test) {
    Unit unit;
    
    unit.give_birth();
    EXPECT_TRUE(unit.is_live());
}

TEST(unit_test, is_live_when_die_test) {
    Unit unit;

    unit.set_age(7);
    unit.check_and_kill();
    EXPECT_FALSE(unit.is_live());
}