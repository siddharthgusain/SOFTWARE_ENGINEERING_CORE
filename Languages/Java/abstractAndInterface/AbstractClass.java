package Languages.Java.abstractAndInterface;

abstract class Parent {
    int a; // Data Members allowed in Abstract class
    // we can't create Object of Abstract Class
    // abstract Parent(){} // can't create abstract Constructor
    // abstract static void test(); // can't create Abstract static method as statis
    // doesnt depend on object and static Method can't be Overridden

    static void test() {

    } // Normal Static Method are possible

    abstract void log1(); // abstract Methods are public by default
}

interface Parent1 {
    // final interface is not allowed
    // int b; // normal Data Members not allowed
    static final int CONSTANT_MEMBER = 10; // All Variables are static and final by default

    default void log2() { // default method allowed in interface
        System.out.println("Parent1 log");
    }

    void display(); // public , abstract by default
}

// Concrete class
class Child1 extends Parent implements Parent1 {

    @Override
    void log1() {
        System.out.println("Child1 log");
    }

    @Override
    public void display() {
        System.out.println("Child2 log");
    }
}

// Concrete class
class Child2 extends Parent {
    @Override
    void log1() {
        System.out.println("Child1 log");
    }
}

public class AbstractClass {
    public static void main(String[] args) {
        Parent child1 = new Child1();
    }
}
