package ParkingLot;

// Enums
enum VehicleType {
    TwoWheeler, FourWheeler
}

// Vehicle class
class Vehicle {
    int vehicleNo;
    VehicleType vehicleType;

    Vehicle(int vehicleNo, VehicleType vehicleType) {
        this.vehicleNo = vehicleNo;
        this.vehicleType = vehicleType;
    }
}