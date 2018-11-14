namespace loadcomplete {
    using int8_t = char;
    
    class Unit {

     public:
        Unit();

        void give_birth();
        void grow_old();

        void set_age(int8_t);
        int8_t get_age() const;

        bool is_live() const;

        void check_and_kill();

        enum UnitState {
            DEATH = -1,
            NEWBORN = 0,
            LIVE = 1,
            TOO_OLD = 7,
        };

     private:
        int8_t age;
    };
}