package Languages.Java.Collections;

class CustomSinglyLinkedList<T> {

    class Node<T> {
        T data;
        Node<T> next;

        Node() {
            this.data = null;
            this.next = null;
        }
    }

    private Node<T> head;
    private Node<T> tail;
    int size;

    CustomSinglyLinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    Node<T> addFirst(T nodeValue) {
        Node<T> temp = new Node<>();
        temp.data = nodeValue;
        temp.next = head;
        head = temp;

        if (size == 0) {
            tail = temp;
        }

        size++;
        return temp;
    }

    Node<T> addLast(T nodeValue) {
        Node<T> temp = new Node<>();
        temp.data = nodeValue;
        temp.next = null;

        if (size == 0) {
            head = tail = temp;
        } else {
            tail.next = temp;
            tail = temp;
        }

        size++;
        return temp;
    }

    Node<T> removeFirst() {
        if (size == 0) {
            throw new IllegalStateException("List is empty");
        }

        Node<T> temp = head;
        head = head.next;

        if (head == null) {
            tail = null;
        }

        size--;
        return temp;
    }

    Node<T> removeLast() {
        if (size == 0) {
            throw new IllegalStateException("List is empty");
        }

        if (size == 1) {
            Node<T> temp = head;
            head = tail = null;
            size--;
            return temp;
        }

        Node<T> current = head;
        while (current.next != tail) {
            current = current.next;
        }

        Node<T> temp = tail;
        tail = current;
        tail.next = null;
        size--;
        return temp;
    }

    Node<T> addAt(int index, T nodeValue) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }

        if (index == 0) {
            return addFirst(nodeValue);
        }

        if (index == size) {
            return addLast(nodeValue);
        }

        Node<T> temp = new Node<>();
        temp.data = nodeValue;

        Node<T> current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current.next;
        }

        temp.next = current.next;
        current.next = temp;
        size++;
        return temp;
    }

    Node<T> removeAt(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }

        if (index == 0) {
            return removeFirst();
        }

        if (index == size - 1) {
            return removeLast();
        }

        Node<T> current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current.next;
        }

        Node<T> temp = current.next;
        current.next = temp.next;
        size--;
        return temp;
    }

    int getSize() {
        return size;
    }
}

/*
 * One LinkedList implementation is Having only head Pointer
 * What will Happen in this case?
 * AddLast and RemoveLast -> O(n)
 * AddFirst and RemoveFirst-> O(1)
 * AddAtIndex and RemoveAtIndex -> O(index)
 */

/*
 * One LinkedList implementation is Having both head and tail Pointer
 * What will Happen in this case?
 * AddLast and RemoveLast -> O(1)
 * AddFirst and RemoveFirst-> O(1)
 * AddAtIndex and RemoveAtIndex -> O(index)
 */
