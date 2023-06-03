class ParkingSystem {
    unordered_map<int, int> slots;
public:
    ParkingSystem(int big, int medium, int small) {
        slots[1] = big;
        slots[2] = medium;
        slots[3] = small;
    }
    
    bool addCar(int carType) {
        auto &has = slots[carType];
        if (!has) return false;
        has--;
        return true;
    }
};