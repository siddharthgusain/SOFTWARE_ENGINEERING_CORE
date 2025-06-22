package Languages.Java.inheritance;

class Base {
    protected int i;

    Base(int i) {
        super(); // Its Parent is Object Class of Java -> Kind of prototype inheritance in JS
        this.i = i;
    }

    public void log() {
        System.out.println("Base");
    }
}

class Derived extends Base {

    public int j;

    Derived(int num) {
        super(num); // calling base class constructor
    }

    @Override
    public void log() {
        super.log();
        System.out.println(this.j); // Current class variable i
        System.out.println(super.i); // parent variable i
    }
}

public class InheritanceExample {
    public static void main(String[] args) {
        Base b = new Derived(100);
        b.log();
        // Derived d = new Base(10); -> Not possible
        // b.j; -> Can't access as type of "b" is Base not Derived
    }
}

// In Java we can't specify type of inheritance like in C++ (private , public
// ,protected)
// Java has different rules