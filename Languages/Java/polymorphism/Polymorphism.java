package Languages.Java.polymorphism;

class Shape {

    @Override
    public String toString() {
        return "Siddharth";
    }

    void area() {
        System.out.println("Shape");
    }
}

class Rectangle extends Shape {
    @Override
    void area() {
        System.out.println("Rectangle Area");
    }

    void area(int a, int b) {
        System.out.println("Rectangle Area with Parameter");
    }
}

public class Polymorphism {
    public static void main(String[] args) {
        Shape s = new Rectangle();
        s.area();
        // s.area(1,2); -> type of s is "Shape" so only area() is accessed
        Rectangle r = new Rectangle();
        r.area(1, 2); // Type of r is "Rectangle" , so both area() and area(int a, int b) is
                      // accessible

        System.out.println(s);// Overriding toString in Shape class
    }
}

// Reference Type i.e left hand side decides which method and variable to access
// Actual Object type i.e right hand side defines which to call (Overriding) ->
// Runtime Polymorphism -> Dynamic Method Dispatch
// For Function Overriding -> Java uses Dynamic Dispatch -> Equivalent to "vptr"
// and "vtable" in C++