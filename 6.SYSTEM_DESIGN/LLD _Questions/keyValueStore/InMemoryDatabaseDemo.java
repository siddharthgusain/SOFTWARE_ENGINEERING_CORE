package com.keyValueStore;

import java.util.*;

// Record Class to hold data
class Record {
    private String id;       // Primary Key
    private String name;     // Secondary Index
    private String email;    // Secondary Index

    public Record(String id, String name, String email) {
        this.id = id;
        this.name = name;
        this.email = email;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    @Override
    public String toString() {
        return "Record{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", email='" + email + '\'' +
                '}';
    }
}

// Database Class to manage records and indexes
class InMemoryDatabase {
    // Primary Index: Maps ID to Record
    private Map<String, Record> primaryIndex = new HashMap<>();

    // Secondary Indexes
    private Map<String, Set<String>> nameIndex = new HashMap<>();  // Maps Name to Set of IDs
    private Map<String, Set<String>> emailIndex = new HashMap<>(); // Maps Email to Set of IDs

    // Add a record
    public void addRecord(Record record) {
        // Add to primary index
        primaryIndex.put(record.getId(), record);

        // Add to secondary indexes
        nameIndex.computeIfAbsent(record.getName(), k -> new HashSet<>()).add(record.getId());
        emailIndex.computeIfAbsent(record.getEmail(), k -> new HashSet<>()).add(record.getId());
    }

    // Get record by primary key
    public Record getRecordById(String id) {
        return primaryIndex.get(id);
    }

    // Get records by name (secondary index)
    public List<Record> getRecordsByName(String name) {
        Set<String> ids = nameIndex.getOrDefault(name, Collections.emptySet());
        List<Record> records = new ArrayList<>();
        for (String id : ids) {
            records.add(primaryIndex.get(id));
        }
        return records;
    }

    // Get records by email (secondary index)
    public List<Record> getRecordsByEmail(String email) {
        Set<String> ids = emailIndex.getOrDefault(email, Collections.emptySet());
        List<Record> records = new ArrayList<>();
        for (String id : ids) {
            records.add(primaryIndex.get(id));
        }
        return records;
    }

    // Delete record by ID
    public void deleteRecord(String id) {
        Record record = primaryIndex.remove(id);
        if (record != null) {
            nameIndex.get(record.getName()).remove(id);
            emailIndex.get(record.getEmail()).remove(id);
        }
    }

    // Update record
    public void updateRecord(String id, Record updatedRecord) {
        deleteRecord(id);
        addRecord(updatedRecord);
    }
}

// Example Usage
public class InMemoryDatabaseDemo {
    public static void main(String[] args) {
        InMemoryDatabase db = new InMemoryDatabase();

        // Adding records
        db.addRecord(new Record("1", "Alice", "alice@example.com"));
        db.addRecord(new Record("2", "Bob", "bob@example.com"));
        db.addRecord(new Record("3", "Alice", "alice.work@example.com"));

        // Query by ID
        System.out.println("Query by ID:");
        System.out.println(db.getRecordById("1"));

        // Query by Name
        System.out.println("\nQuery by Name:");
        System.out.println(db.getRecordsByName("Alice"));

        // Query by Email
        System.out.println("\nQuery by Email:");
        System.out.println(db.getRecordsByEmail("bob@example.com"));

        // Update a record
        System.out.println("\nUpdate Record:");
        db.updateRecord("2", new Record("2", "Bobby", "bobby@example.com"));
        System.out.println(db.getRecordById("2"));

        // Delete a record
        System.out.println("\nDelete Record:");
        db.deleteRecord("1");
        System.out.println(db.getRecordById("1"));
    }
}
