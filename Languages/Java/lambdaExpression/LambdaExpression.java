package Languages.Java.lambdaExpression;

@FunctionalInterface
interface FunctionInterfaceExample {
    public int add(int a, int b);
}

public class LambdaExpression {
    public static void main(String[] args) {
        FunctionInterfaceExample f = (int a, int b) -> {
            return a + b;
        };
        System.out.println(f.add(1, 2));
    }
}
