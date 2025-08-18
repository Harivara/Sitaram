package TicTacToe;

public class Player {

    String name;
    PlayingPiece piece;

    Player(String name, PlayingPiece type) {
        this.name = name;
        this.piece = type;
    }

    public void setName(String name) {
        this.name = name;
    }

    public PlayingPiece getPiece() {
        return piece;
    }

    public void setPiece(PlayingPiece piece) {
        this.piece = piece;
    }

    public String getname() {
        return name;
    }

}
