package Languages.Java.controlFlow;

import java.util.Scanner;

public class controlFlow {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int age = scn.nextInt();

        if (age > 50) {
            System.out.println("You are Old");
        } else {
            System.out.println("You are Young");
        }

        for (int i = 0; i < 10; i++) {
            System.out.println(i);
        }

        switch (age) {
            case 50:
                System.out.println("You are Old");
                break;
            case 25:
                System.out.println("You are Young");
                break;
        }
    }
}
