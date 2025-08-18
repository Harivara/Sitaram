package SystemDesign.ParkingLot.ParkingSpot.Manager;

import java.util.ArrayList;

import SystemDesign.ParkingLot.ParkingSpot.ParkingSpot;
import SystemDesign.ParkingLot.ParkingSpot.Stratagy.ParkNearEntrance;
import SystemDesign.ParkingLot.ParkingSpot.Stratagy.ParkingStratagy;

public class FourWheelerManager extends ParkingSpotManager{
    private ParkingSpot parkingspot;
    private static ArrayList<ParkingSpot> fourwheelerparkingspots = new ArrayList<>();
    private static ParkingStratagy nearEntrance=new ParkNearEntrance();
 
    //When super(..) is called Java requires that argument is already initialized before super call happens 
    // but instance variables(without static)  are not initialized until after the super() call finishes
    // IF we use static the variable exists before any boject of TwoWheelerManager is created

    public FourWheelerManager() {
        super(fourwheelerparkingspots,nearEntrance);
    }
    
}
