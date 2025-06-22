package Languages.Java.abstractAndInterface;

interface Interface1{
    default void log(){
        System.out.println("Interface1");
    }
}

interface Interface2{
    default void log(){
        System.out.println("Interface2");
    }
}

class Implementation implements Interface1,Interface2{
    public int a = 10;

    @Override
    public void log() {
        Interface1.super.log();
        Interface2.super.log();
        System.out.println("log");
    }
}

public class InterfaceInDepth {
    public static void main(String[] args) {
        Implementation obj = new Implementation();
        Interface1 obj1 = new Implementation();
        obj.log();
        System.out.println(obj.a); // allowed as obj is of type Implementation
//        System.out.println(obj1.a); // not allowed as obj1 is of Type Interface1

// Type of Object determines which Methods and Variables are accessible
// Actual Object Memory Depends on right hand side
    }
}
