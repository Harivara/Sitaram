package SystemDesign.Elevator;

public class Floor {
    int floor;
    ExternalButtonDispatcher externalButtonDispatcher;

    public Floor(int floor){
    
        this.floor=floor;
        externalButtonDispatcher=new ExternalButtonDispatcher();

    }

    public void pressbutton(DirectionType direction){
        externalButtonDispatcher.submitExternalRequest(floor, direction);
    }
}
