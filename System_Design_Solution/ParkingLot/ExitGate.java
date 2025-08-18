package ParkingLot;
// ExitGate class

import java.util.ArrayList;

class ExitGate {
    ParkingSpotManagerFactory factory;

    ExitGate(ParkingSpotManagerFactory factory) {
        this.factory = factory;
    }

    void removeVehicle(Ticket ticket) {
        if (ticket == null || ticket.vehicle == null) {
            System.out.println("Invalid ticket");
            return;
        }
        ParkingSpotManager manager = factory.getParkingSpotManager(ticket.vehicle.vehicleType, new ArrayList<>());
        manager.removeVehicle(ticket.vehicle);
    }
}