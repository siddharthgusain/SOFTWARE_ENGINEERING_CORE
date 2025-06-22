package Languages.Java.Collections;

public class CustomDoublyLinkedList<T> {

    class Node<T> {
        T data;
        Node<T> prev;
        Node<T> next;

        Node(T data) {
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }

    private Node<T> head;
    private Node<T> tail;
    private int size;

    public CustomDoublyLinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    // Add element at the start of the list
    public void addFirst(T data) {
        Node<T> newNode = new Node<>(data);
        if (head == null) {
            head = tail = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Add element at the end of the list
    public void addLast(T data) {
        add(data); // Alias for add
    }

    // Remove the first element of the list
    public T removeFirst() {
        if (head == null) {
            throw new IllegalStateException("List is empty");
        }
        Node<T> toRemove = head;
        head = head.next;
        if (head != null) {
            head.prev = null;
        } else {
            tail = null; // List becomes empty
        }
        size--;
        return toRemove.data;
    }

    // Remove the last element of the list
    public T removeLast() {
        if (tail == null) {
            throw new IllegalStateException("List is empty");
        }
        Node<T> toRemove = tail;
        tail = tail.prev;
        if (tail != null) {
            tail.next = null;
        } else {
            head = null; // List becomes empty
        }
        size--;
        return toRemove.data;
    }

    // Add element at the end (already implemented)
    public void add(T data) {
        Node<T> newNode = new Node<>(data);
        if (head == null) {
            head = tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Remove element at a specific index (already implemented)
    public T remove(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Invalid index");
        }
        if (index == 0) {
            return removeFirst();
        } else if (index == size - 1) {
            return removeLast();
        } else {
            Node<T> current = head;
            for (int i = 0; i < index; i++) {
                current = current.next;
            }
            T data = current.data;
            current.prev.next = current.next;
            current.next.prev = current.prev;
            size--;
            return data;
        }
    }

    // Utility and traversal methods (size, get, printList)
    public T get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Invalid index");
        }
        Node<T> current = head;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        return current.data;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void printList() {
        Node<T> current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}

// JAVA Default List is Doubly with Two Pointers Head and Tail