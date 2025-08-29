package SystemDesign.Elevator;

import java.util.List;

public class ExternalButtonDispatcher {

    List<ElevatorController> elevatorControllerList=ElevatorCreator.elevatorControllerList;

    public void submitExternalRequest(int floor, DirectionType direction) {


        //EVEN ODD
        for(ElevatorController elevatorController: elevatorControllerList){
            int elevatorId=elevatorController.elevtorcarobj.id;
            if(elevatorId%2==1 && floor%2==1){
                elevatorController.SubmitExternalRequest(floor,direction);
            }
            else if(elevatorId%2==0 && floor%2==0){
                elevatorController.SubmitExternalRequest(floor, direction);
            }
        }
    }

}
