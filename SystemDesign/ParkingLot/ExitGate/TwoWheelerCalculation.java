package SystemDesign.ParkingLot.ExitGate;

import SystemDesign.ParkingLot.ParkingSpot.ParkingSpot;
import SystemDesign.ParkingLot.Ticket.Ticket;

public class TwoWheelerCalculation implements PricingStratagy {

    private ParkingSpot parkingSpot;

    @Override
  public int getprice(){
       return parkingSpot.getPrice();
  }

    
}
