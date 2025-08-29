package SystemDesign.Elevator;

public class InternalButton {

    InternalButtonDispatcher dispatcher=new InternalButtonDispatcher();

    int[] avaiableButtons={1,2,3,4,5,6,7,8,9,10};
    int buttonSellected;

    void pressbutton(int destination,ElevatorCar elevatorCar) {
        
        //1. check if destination is in the list of avaiable floors

        //2.submit the request to the jobDispatcher
        dispatcher.submitInternalRequest(destination,elevatorCar);
    }
}
