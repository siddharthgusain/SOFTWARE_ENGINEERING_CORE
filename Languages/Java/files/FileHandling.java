package Languages.Java.files;

import java.io.*;
import java.util.Scanner;

public class FileHandling {
    public static void main(String[] args) {

        try {
            File meta = new File("name.txt"); // File meta and attributes
            meta.createNewFile();

            FileWriter f1 = new FileWriter(meta.getName(), true); // For writing to File
            f1.write('a');
            f1.close();

            FileReader f = new FileReader(meta.getName()); // Reading from File
            while (f.ready()) {
                int data = f.read();
                System.out.print((char) data);
            }

            meta.delete();
        } catch (Exception e) {
            System.out.println(e);
        }

    }
}

/*
 * Data is of two types
 * Internal Program Data -> Inbuilt Data types/Variables , Objects/Custom Data
 * Type
 * Data from external Device like HDD , NIC , Keyboard -> Known as Files
 */