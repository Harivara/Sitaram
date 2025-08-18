package SystemDesign.ParkingLot;

public class Vechicle {
    private String licence;

    public Vechicle(String licenceplate){
        this.licence=licenceplate;
    }

    public String getLicence() {
        return licence;
    }

    public void setLicence(String licence) {
        this.licence = licence;
    }
}
