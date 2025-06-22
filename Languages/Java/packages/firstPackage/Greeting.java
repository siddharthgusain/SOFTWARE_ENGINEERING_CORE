package Languages.Java.packages.firstPackage;

import static Languages.Java.packages.secondPackage.Greeting.publicMethod; // Import is similar to #include

public class Greeting {
    public static void main(String[] args) {
        System.out.println("First Package First File Main Function");
        publicMethod();
    }
}

// 1 Package can have Multiple Files -> Similar to "namespaces" in CPP
// 1 File can have Multiple Classes
// Classes from package 1 can be used in package 2 vice versa