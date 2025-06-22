package Languages.Java.introduction;

import java.lang.System;
import java.util.Scanner;

public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello World");
        Scanner input = new Scanner(System.in);
        System.out.println(input.nextLine()); // Take Whole Line
        System.out.println(input.next()); // First word
        System.out.println(input.nextInt()); // integer
    }
}
