package Languages.Java.stream;

import java.util.Arrays;

public class Stream {
    public static void main(String[] args) {
        int[] arr = { 1, 34442, 2, 2, 2 };

        Arrays.stream(arr).filter(i -> i % 2 == 0).forEach(element -> System.out.println(element));
        // Code Size for Developer Decreased
        // Readable
        // Functional Programming
    }
}
