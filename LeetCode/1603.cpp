class ParkingSystem {
public:
    int a[4];
    ParkingSystem(int big, int medium, int small) {
        a[3] = small;
        a[2] = medium;
        a[1] = big;
    }
    
    bool addCar(int carType) {
        if (a[carType]) {
            a[carType] -- ;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */