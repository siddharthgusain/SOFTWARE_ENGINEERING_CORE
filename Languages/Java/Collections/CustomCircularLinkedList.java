package Languages.Java.Collections;

public class CustomCircularLinkedList<T> {

    class Node<T> {
        T data;
        Node<T> next;

        Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node<T> head;
    private Node<T> tail;
    private int size;

    public CustomCircularLinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    // Add an element at the end of the list
    public void addLast(T data) {
        Node<T> newNode = new Node<>(data);
        if (head == null) { // Empty List
            head = tail = newNode;
            tail.next = head; // Make it circular
        } else { // List with at least One node
            tail.next = newNode;
            tail = newNode;
            tail.next = head; // Maintain circular link
        }
        size++;
    }

    // Add an element at the beginning of the list
    public void addFirst(T data) {
        Node<T> newNode = new Node<>(data);
        if (head == null) {
            head = tail = newNode;
            tail.next = head; // Make it circular
        } else {
            newNode.next = head;
            head = newNode;
            tail.next = head; // Maintain circular link
        }
        size++;
    }

    // Remove the first element of the list
    public T removeFirst() {
        if (head == null) {
            throw new IllegalStateException("List is empty");
        }
        T data = head.data;
        if (head == tail) { // Single element case
            head = tail = null;
        } else {
            head = head.next;
            tail.next = head; // Maintain circular link
        }
        size--;
        return data;
    }

    // Remove the last element of the list
    public T removeLast() {
        if (head == null) {
            throw new IllegalStateException("List is empty");
        }
        T data = tail.data;
        if (head == tail) { // Single element case
            head = tail = null;
        } else {
            Node<T> current = head;
            while (current.next != tail) { // Traverse to the second last node
                current = current.next;
            }
            tail = current;
            tail.next = head; // Maintain circular link
        }
        size--;
        return data;
    }

    // Get the size of the list
    public int size() {
        return size;
    }

    // Check if the list is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Display the list elements
    public void printList() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        Node<T> current = head;
        do {
            System.out.print(current.data + " ");
            current = current.next;
        } while (current != head);
        System.out.println();
    }
}

// We can Implement Circular List with Singly or Doubly
// Each implementation will have different Complexity for all operations