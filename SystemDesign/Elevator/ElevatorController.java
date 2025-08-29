package SystemDesign.Elevator;

import java.util.PriorityQueue;

public class ElevatorController {

    ElevatorCar elevtorcarobj;
    PriorityQueue<Integer> upMinQ;
    PriorityQueue<Integer> downMaxQ;

    public ElevatorController(ElevatorCar elecatorCar){
        this.elevtorcarobj=elecatorCar;
        upMinQ=new PriorityQueue<>();
        downMaxQ=new PriorityQueue<>((a,b)->b-a);
    }

    void SubmitExternalRequest(int floor, DirectionType direction) {
        if(direction==DirectionType.Down){
            downMaxQ.offer(floor);
        }
        else{
            upMinQ.offer(floor);
        }
    }
    public void SubmitInternalRequest(int floor){

    }

    public void ControlElevatorCar() {
        while (true) {
            if(elevtorcarobj.direction==DirectionType.Up){

            }
        }
    }
}
