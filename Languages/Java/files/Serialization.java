package Languages.Java.files;

import java.io.*;

class Person implements Serializable {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person{name='" + name + "', age=" + age + '}';
    }
}

class DeserializationExample {
    public static void deserialize() {
        try (FileInputStream fileIn = new FileInputStream("person.txt");
                ObjectInputStream in = new ObjectInputStream(fileIn)) {
            Person person = (Person) in.readObject();
            System.out.println("Deserialized object: " + person);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class Serialization {
    public static void main(String[] args) {
        Person person = new Person("Alice", 30);
        try (FileOutputStream fileOut = new FileOutputStream("person.txt");
                ObjectOutputStream out = new ObjectOutputStream(fileOut)) {
            out.writeObject(person);
            System.out.println("Object serialized successfully.");
        } catch (Exception e) {
            e.printStackTrace();
        }

        DeserializationExample.deserialize();
    }
}
