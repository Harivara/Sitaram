package SystemDesign.ParkingLot.ParkingSpot.Manager;

import java.util.ArrayList;

import SystemDesign.ParkingLot.ParkingSpot.ParkingSpot;
import SystemDesign.ParkingLot.ParkingSpot.Stratagy.ParkNearElevator;
import SystemDesign.ParkingLot.ParkingSpot.Stratagy.ParkingStratagy;


public class TwoWheelerManager extends ParkingSpotManager {

    private ParkingSpot parkingspot;
    private static ArrayList<ParkingSpot> twowheelerparkingspots = new ArrayList<>();
    private static ParkingStratagy nearElevator=new ParkNearElevator();
 
    //When super(..) is called Java requires that argument is already initialized before super call happens 
    // but instance variables(without static)  are not initialized until after the super() call finishes
    // IF we use static the variable exists before any boject of TwoWheelerManager is created

    public TwoWheelerManager() {
        super(twowheelerparkingspots,nearElevator);
    }
    
   
}
