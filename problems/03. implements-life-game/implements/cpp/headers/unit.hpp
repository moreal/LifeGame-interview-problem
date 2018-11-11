namespace loadcomplete {
    using uint8_t = unsigned char;
    
    class Unit {

     public:
        void GiveBirth();
        void GrowOld();

        void SetAge(uint8_t);
        uint8_t GetAge() const;

        bool IsLive() const;

        void CheckAndKill();

     private:
        uint8_t age;
    };
}