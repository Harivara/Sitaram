package SystemDesign.ParkingLot.ParkingSpot.Manager;

import java.util.ArrayList;

import SystemDesign.ParkingLot.ParkingSpot.ParkingSpot;
import SystemDesign.ParkingLot.ParkingSpot.Stratagy.ParkingStratagy;

public class ParkingSpotManager {
    private ArrayList<ParkingSpot>parkingspots;
    ParkingStratagy parkingStratagy;

    public ParkingSpotManager(ArrayList<ParkingSpot> ParkingSpots,ParkingStratagy parkingStratagy){
        this.parkingspots=ParkingSpots;                                        // THIS WILL BE DYNAMIC
        this.parkingStratagy=parkingStratagy;
    }

     public void setParkingSpots(ArrayList<ParkingSpot> spots) {
        this.parkingspots = spots;
    }

    //FIND
    //ADD praking space
    //REMOVE parking space
    //PARK vehicle
    // Remove vehicle
}



    
    
    
