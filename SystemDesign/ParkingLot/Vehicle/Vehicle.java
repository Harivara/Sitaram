package SystemDesign.ParkingLot.Vehicle;

import SystemDesign.ParkingLot.ParkingSpot.ParkingSpot;

public class Vehicle {
    private int vehicle_number;

    public enum VehicleType{
        TWO_WHEELER, FOUR_WHEELER
    }

    private VehicleType type;
    

    public VehicleType gettype(){
        return type;
    }

    
}
