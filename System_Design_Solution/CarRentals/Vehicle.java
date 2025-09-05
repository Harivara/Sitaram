package System_Design_Solution.CarRentals;

enum VehicleType{
    Bike,Car
}

enum VechicleStatus{
    Maintance,Rented,Avaiable
}

public class Vehicle {
    
    int VehicleId;
    int VehicleNumber;
    VehicleType vehicleType;
    String companyName;
    String modalname;
    int KmDriven;
    Date manufactureDate;
    VehicleStatus status;
    
    

}
