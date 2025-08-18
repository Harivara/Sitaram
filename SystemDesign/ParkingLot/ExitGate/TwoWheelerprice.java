package SystemDesign.ParkingLot.ExitGate;

import SystemDesign.ParkingLot.ParkingSpot.ParkingSpot;

public class TwoWheelerprice implements PricingStratagy {

    private ParkingSpot parkingSpot;

    @Override
    public int getprice() {
        return parkingSpot.getPrice();
    }

}
