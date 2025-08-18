package TicTacToe;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.List;

public class Game {
    Deque<Player> players;
    Board board;

    Game() {
        InitializeGame();
    }

    public void InitializeGame() {
        // Creating two players
        players = new LinkedList<>();

        PieceX crosspiece = new PieceX(); // PieceX gets the pieceType of Piece
        Player player1 = new Player("p1", crosspiece); // Player allots the piece dynamically using constructor

        PieceY round = new PieceY();
        Player player2 = new Player("p2", round);

        players.add(player1);
        players.add(player2);

        board = new Board(3);
    }

    public String StartGame() {
        Boolean noWinner = true;
        while (noWinner) {
            // take out the player and push it back
            Player playerturn = players.removeFirst();

            // get the free space from the board
            board.printBoard();
            List<Pair<Integer, Integer>> freespaces = board.getFreeCells();
            if (freespaces.isEmpty()) {
                noWinner = false;
                continue;
            }

            // If there is free space take the user Input
            System.out.println("Player: " + playerturn.name + "Enter row,column");
            Scanner inputScanner = new Scanner(System.in);
            String s = inputScanner.nextLine();
            String[] values = s.split(",");
            int inputRow = Integer.valueOf(values[0]);
            int inputCol = Integer.valueOf(values[1]);

            // place the piece
            boolean pieceAddedSuccessfully = board.addPiece(inputRow, inputCol, playerturn.piece);
            if (!pieceAddedSuccessfully) {
                // player cannot insert piece into this cell select another cell
                System.out.println("Incorrect position chosen, Try again");
                players.addFirst(playerturn);
                continue;
            }
            // placed in position
            players.addLast(playerturn);

            boolean winner = isThereWinner(inputRow, inputCol, playerturn.piece.pieceType);
            if (winner) {
                board.printBoard();
                return playerturn.name;
            }
        }
        return "tie";
    }

    public boolean isThereWinner(int row, int col, PieceType pieceType) {
        boolean rowMatch = true;
        boolean colMatch = true;
        boolean diagonalMatch = true;
        boolean antidiagonalMatch = true;

        // need to check row
        for (int i = 0; i < board.size; i++) {
            if (board.board[row][i] == null || board.board[row][i].pieceType != pieceType) {
                rowMatch = false;
            }
        }

        // need to check column
        for (int i = 0; i < board.size; i++) {
            if (board.board[i][col] == null || board.board[i][col].pieceType != pieceType) {
                colMatch = false;
            }
        }

        // need to check diagonals
        for (int i = 0, j = 0; i < board.size; i++, j++) {
            if (board.board[i][j] == null || board.board[i][j].pieceType != pieceType) {
                diagonalMatch = false;
            }
        }
        // need to check antidiagonals
        for (int i = 0, j = board.size - 1; i < board.size; i++, j--) {
            if (board.board[i][j] == null || board.board[i][j].pieceType != pieceType) {
                antidiagonalMatch = false;
            }
        }

        return rowMatch || colMatch || diagonalMatch || antidiagonalMatch;
    }

}
