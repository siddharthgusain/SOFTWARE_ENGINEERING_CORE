package Languages.Java.accessModifiers.PrivateModifierExample;

public class PrivateModifier { // top level classes can't be private
    private int privateVariable;

    private void privateMethod() {
    }

    private class utility { // Nested classes can be private
    }
}

// Private Variables can be accesses within same class , can't be accesses
// directly in Derived class as well
// Private Methods are same
