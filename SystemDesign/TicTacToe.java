

public class TicTacToe {
    Board board=new Board(3);

    public static void main(String[] args){
        TicTacToe game =new TicTacToe();
        game.board.printBoard();
    }
    

}
enum PieceType{
    O,X
}

class Player {
    String playername;
    PieceType playerpiece;

    Player(String name, PieceType type){
        this.playername=name;
        this.playerpiece=type;
    }

}

class Board {
    PieceType[][] board;
    int size;
    
    Board(int size){
        this.size=size;
        this.board=new PieceType[size][size];
    }

    boolean addPiece(int row, int col, PieceType piece) {
        if (row < 0 || row >= size || col < 0 || col >= size) {
            System.out.println("Invalid move: out of bounds!");
            return false;
        }
        if (board[row][col] != null) {
            System.out.println("Invalid move: cell already occupied!");
            return false;
        }
        board[row][col] = piece;
        return true;
    }
    
    void printBoard(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                System.out.print(board[i][j]==null ? "-": board[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }
    

}
