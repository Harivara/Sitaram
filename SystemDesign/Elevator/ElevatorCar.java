package SystemDesign.Elevator;

enum StateType {
    Running, Steady
}

public class ElevatorCar {
    int id;
    ElevatorDisplay display;
    int currentfloor;
    DirectionType direction;
    StateType state;
    InternalButton internalbuttons;
    ElevatorDoor elevatorDoor;

    public ElevatorCar(){
        display=new ElevatorDisplay();
        internalbuttons=new InternalButton();
        state=StateType.Steady;
        currentfloor=0;
        direction=DirectionType.Up;

    }

    public void showDisplay(){
        display.showDisplay();
    }

    public void pressbutton(int destination){
        internalbuttons.pressbutton(destination,this);
    }

    public void setDisplay(){
        this.display.setDisplay(currentfloor, direction);
    }

   boolean moveElevator(DirectionType direction, int destination){
        int startfloor=currentfloor;
        if(direction==DirectionType.Up){
            for(int i=startfloor;i<=destination;i++){
                this.currentfloor=startfloor;
                setDisplay();
                showDisplay();
                if(i==destination){
                    return true;
                }
            }
        }
        if(direction==DirectionType.Down){
            for(int i=startfloor;i>=destination;i--){
                this.currentfloor=startfloor;
                setDisplay();
                showDisplay();
                if(i==destination){
                    return true;
                }
                
            }
        }
        return false;
   }
}
