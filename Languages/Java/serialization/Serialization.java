package Languages.Java.serialization;

import java.io.*;

class Student implements Serializable {
    public int id;
    public String name;

    Student(int id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public String toString() {
        return "Student [id=" + id + ", name=" + name + "]";
    }
}

public class Serialization {
    public static void main(String[] args) {
        Student s1 = new Student(1, "John");

        try {
            File file = new File("student.txt");
            file.createNewFile();

            ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(file));
            out.writeObject(s1);
            out.close();

            ObjectInputStream in = new ObjectInputStream(new FileInputStream(file));
            Student s2 = (Student) in.readObject();
            in.close();
            System.out.println(s2);
            System.out.println(s2.id);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
