package Languages.Java.accessModifiers.ProtectedModiferExample;

public class ProtectedClass {
    protected int a;

    protected void log() {
    }

    protected class utility {
    }
}

// Protected variable can be directly accessed within subclass of same package or same file or different package
// Protected Methods have same rules
// Protected Members can't be directly access outside parent and derived