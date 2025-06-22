package Languages.Java.classBasic;

final class Student {
    int rollno;
    String name;

    Student() {
        this.rollno = 0;
        this.name = "";
    }

    Student(int rollno, String name) {
        this.rollno = rollno;
        this.name = name;
    }

    // Java doesn't Support Destructors -> As it is handled by Garbage Collector
    // There is no support for operator overloading

}

public class ClassBasic {
    public static void main(String[] args) {
        Student st1; // Stack Variable
        st1 = new Student(2, "Siddharth"); // Dynamic Mem Allocation by OS system call
        Student st2 = st1; // Shallow Copy
        System.out.println(st1.name);
        System.out.println(st1.rollno);

        st2.name = "Sid";
        st2.rollno = 22;
        System.out.println(st1.name);
        System.out.println(st1.rollno);
    }
}
