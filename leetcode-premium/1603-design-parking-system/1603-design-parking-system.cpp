class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small): big(big), small(small), medium(medium) {}
    
    bool addCar(int carType) {
        switch (carType) {
            case CarType::BIG:
                if (big == 0) return false;
                big--;
                break;
             case CarType::MEDIUM:
                if (medium == 0) return false;
                medium--;
                break;
             case CarType::SMALL:
                if (small == 0) return false;
                small--;
                break;
        }
        return true;
    }
private:
    enum CarType {
        BIG = 1,
        MEDIUM = 2,
        SMALL = 3
    };
    int big, medium, small;
};