namespace loadcomplete {
    using uint8_t = unsigned char;
    
    class Unit {

     public:
        Unit();

        void GiveBirth();
        void GrowOld();

        void SetAge(uint8_t);
        uint8_t GetAge() const;

        bool IsLive() const;

        void CheckAndKill();


        enum UnitState {
            DEATH = -1,
            NEWBORN = 0,
            LIVE,
            TOO_OLD = 7,
        };

     private:
        uint8_t age;
    };
}