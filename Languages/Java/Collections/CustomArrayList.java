package Languages.Java.Collections;

import java.util.Arrays;

class CustomArrayList<T> {
    private T[] arr;
    private int capacity;
    private int size;
    private final int DEFAULT_CAPACITY = 1;

    CustomArrayList() {
        arr = (T[]) new Object[DEFAULT_CAPACITY];
        capacity = DEFAULT_CAPACITY;
    }

    CustomArrayList(int initialCapacity) {
        if (initialCapacity < 0) {
            throw new IllegalArgumentException("Illegal Capacity: " + initialCapacity);
        }
        arr = (T[]) new Object[initialCapacity];
        capacity = initialCapacity;
    }

    private void ensureCapacity() {
        if (size == capacity) {
            int newCapacity = capacity * 2;
            arr = Arrays.copyOf(arr, newCapacity);
            capacity = newCapacity;
        }
    }

    public boolean add(T element) {
        ensureCapacity();
        arr[size++] = element;
        return true;
    }

    // Add an element at a specific index
    public void add(int index, T element) {
        // Check if the index is valid
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }

        ensureCapacity(); // Ensure there is enough capacity

        // Shift elements to the right to make room for the new element
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }

        arr[index] = element; // Insert the new element
        size++; // Increase the size
    }

    public T get(int index) {
        if (index < 0 || index >= size) {
            throw new IllegalArgumentException("Index out of bounds");
        }
        return arr[index];
    }

    public T removeLast() {
        if (size == 0) {
            throw new IllegalArgumentException("Cannot remove from an empty array");
        }
        T element = arr[size - 1];
        size--;
        return element;
    }

    // Remove an element at a specific index
    public T remove(int index) {
        if (index < 0 || index >= size) {
            throw new IllegalArgumentException("Index out of bounds");
        }

        T removedElement = (T) arr[index];

        // Shift elements to the left to fill the gap
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        arr[--size] = null; // Clear the last element
        return removedElement;
    }

    public void display() {
        T[] validElements = Arrays.copyOfRange(arr, 0, size);
        System.out.println("Array: " + Arrays.toString(validElements));
    }
}
