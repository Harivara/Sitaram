package SystemDesign.ParkingLot.ParkingSpot;

import SystemDesign.ParkingLot.Vehicle.Vehicle;

public class ParkingSpot {
    private int id;
    private boolean isEmpty;
    private Vehicle vehicle;
    private int price;


    public void parkVehicle(Vehicle vehicle){
        this.vehicle=vehicle;
        isEmpty=false;

    }

    public void removeVehicle(Vehicle vehicle){
        vehicle=null;
        isEmpty=true;
    }



    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public boolean isEmpty() {
        return isEmpty;
    }
    public void setEmpty(boolean isEmpty) {
        this.isEmpty = isEmpty;
    }
    public Vehicle getVechicle() {
        return vehicle;
    }
    public void setVechicle(Vehicle vehicle) {
        this.vehicle = vehicle;
    }
    public int getPrice() {
        return price;
    }
    public void setPrice(int price) {
        this.price = price;
    }

    

    
}
