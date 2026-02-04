package SnakeLadder;

import java.util.Queue;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        System.out.println("Start Game");

        Scanner scan = new Scanner(System.in);

        System.out.println("Enter Number of Players");
        int n = scan.nextInt();
        scan.nextLine(); // consume leftover newline

        Queue<Player> players = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            System.out.println("Enter Player name " + (i + 1));
            String name = scan.nextLine();

            Player player = new Player(name);
            players.offer(player); // add to queue
        }

        System.out.println("\nPlayers in order:");
        for (Player p : players) {
            System.out.println(p.getName());
        }

        scan.close();
    }
}
