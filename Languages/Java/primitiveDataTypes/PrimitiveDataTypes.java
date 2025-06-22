package Languages.Java.primitiveDataTypes;

public class PrimitiveDataTypes {
    public static void main(String[] args) {
        // 1. Integral Types
        byte byteValue = 100; // Range: -128 to 127
        short shortValue = 32000; // Range: -32,768 to 32,767
        int intValue = 100000; // Range: -2,147,483,648 to 2,147,483,647
        long longValue = 123456789L; // Range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

        // 2. Floating-Point Types
        float floatValue = 3.14f; // Single-precision, approx. 6-7 decimal digits
        double doubleValue = 3.14159265359; // Double-precision, approx. 15-16 decimal digits

        // 3. Character Type
        char charValue = 'A'; // Holds a single Unicode character

        // 4. Boolean Type
        boolean isJavaFun = true; // Holds either true or false

        // Displaying Values
        System.out.println("Primitive Data Types in Java:");
        System.out.println("byte: " + byteValue);
        System.out.println("short: " + shortValue);
        System.out.println("int: " + intValue);
        System.out.println("long: " + longValue);
        System.out.println("float: " + floatValue);
        System.out.println("double: " + doubleValue);
        System.out.println("char: " + charValue);
        System.out.println("boolean: " + isJavaFun);

        // Performing Operations
        int sum = byteValue + shortValue; // Adding byte and short
        double product = floatValue * doubleValue; // Multiplying float and double
        char nextChar = (char) (charValue + 1); // Incrementing a char

        System.out.println("\nOperations with Primitive Types:");
        System.out.println("Sum of byte and short: " + sum);
        System.out.println("Product of float and double: " + product);
        System.out.println("Next character after '" + charValue + "': " + nextChar);
    }
}

// Unsigned Values are not there in Java
// All primitive types are present in Stack of Process Memory space