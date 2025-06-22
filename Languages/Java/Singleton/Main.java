package Languages.Java.Singleton;

class Singleton {

    private static Singleton instance;

    private Singleton() {
    };

    public static synchronized Singleton getInstance() { // Thread Safe function with locks
        if (instance == null)
            instance = new Singleton();
        return Singleton.instance;
    }
}

public class Main {
    public static void main(String[] args) {
        Singleton obj1 = Singleton.getInstance();
        Singleton obj2 = Singleton.getInstance();
    }
}