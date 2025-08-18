package SystemDesign.ParkingLot.EntranceGate;

import SystemDesign.ParkingLot.ParkingSpot.Manager.FourWheelerManager;
import SystemDesign.ParkingLot.ParkingSpot.Manager.ParkingSpotManager;
import SystemDesign.ParkingLot.ParkingSpot.Manager.TwoWheelerManager;
import SystemDesign.ParkingLot.Vehicle.Vehicle;
import SystemDesign.ParkingLot.Vehicle.Vehicle.VehicleType;


public class ParkingSpotFactoryManager {

    private ParkingSpotManager getParkingSpotManager(Vehicle vehicle) {
        if (vehicle.gettype() == Vehicle.VehicleType.TWO_WHEELER) {
            return new TwoWheelerManager();
        } else if (vehicle.gettype() == Vehicle.VehicleType.FOUR_WHEELER) {
            return new FourWheelerManager();
        }
        throw new IllegalArgumentException("Unsupported vehicle type: " + vehicle.gettype());
    }
}
