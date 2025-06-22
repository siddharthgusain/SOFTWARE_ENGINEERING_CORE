package Languages.Java.packages.secondPackage;

public class Greeting {
    public static void main(String[] args) {
        System.out.println("Second Package");
    }

    public static void publicMethod() {
        System.out.println("From Greeting of secondPackage");
    }

    protected void protectedMethod() {

    }

    void defaultMethod() {
        System.out.println("From Greeting File in secondPackage");
    }
}
