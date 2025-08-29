package SystemDesign.Elevator;

enum DirectionType {
    Up,
    Down
}

public class ElevatorDisplay {
    public int floor;
    public DirectionType direction;

    public void setDisplay(int floor, DirectionType direction){
        this.floor=floor;
        this.direction=direction;
    }

    public void showDisplay(){
        System.out.println(floor);
        System.out.println(direction);
    }
}
