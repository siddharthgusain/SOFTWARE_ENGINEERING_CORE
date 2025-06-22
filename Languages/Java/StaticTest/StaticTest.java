package Languages.Java.StaticTest;

class StaticExample {
    static int i; // Shared by all Objects of this class
    int j;

    static { // static block
        i = 10;
    }

    static class StaticNestedClass {
        void printFromNestedClass() {
            System.out.println(i);
        }
    }
}

public class StaticTest {
    public static void main(String[] args) { // Static Method can be invoked by Class name , doesn't bind to object
        System.out.println("Hello");
        System.out.println(StaticExample.i);
        StaticExample.StaticNestedClass st = new StaticExample.StaticNestedClass();
        st.printFromNestedClass();
    }
}

// Static Variables shared by all Objects
// Static Methods are invoked by class name , can't access non static variables
// of class
// static block can initialize static variable