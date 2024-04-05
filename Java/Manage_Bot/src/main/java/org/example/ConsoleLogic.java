package org.example;

import java.util.Scanner;

public class ConsoleLogic {
    final private Scanner scanner;


    public ConsoleLogic() {
        scanner = new Scanner(System.in);
    }




    public String getUserInput() {
        return scanner.nextLine();
    }

    public void displayMessage(String message) {
        System.out.println(message);
    }
}