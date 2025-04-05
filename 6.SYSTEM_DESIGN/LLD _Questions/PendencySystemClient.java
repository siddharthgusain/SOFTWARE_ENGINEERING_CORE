package Phonepe;

import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

interface CountingStrategy {
    int count(Map<String, Integer> tagCountMap, List<String> tags);
}

class DefaultCountStrategy implements CountingStrategy {
    @Override
    public int count(Map<String, Integer> tagCountMap, List<String> tags) {
        String tagHierarchy = String.join(":", tags);
        return tagCountMap.getOrDefault(tagHierarchy, 0);
    }
}

class Entity {
    int id;
    List<String> tags;

    Entity(int id, List<String> tags) {
        this.id = id;
        this.tags = tags;
    }

    // getters and setters
}

class PendencySystem {
    private static PendencySystem instance;
    private Map<Integer, List<String>> entityMap;
    private Map<String, Integer> tagCountMap;
    private CountingStrategy countingStrategy;

    private PendencySystem() {
        entityMap = new ConcurrentHashMap<>(); // For Thread Safety
        tagCountMap = new ConcurrentHashMap<>();
        countingStrategy = new DefaultCountStrategy();
    }

    public static synchronized PendencySystem getInstance() {
        if (instance == null) {
            instance = new PendencySystem();
        }
        return instance;
    }

    public synchronized void startTracking(Entity e) {
        // Check if tag id already exits
        entityMap.putIfAbsent(e.id, e.tags);
        // The system must support both partial and full tag hierarchies.
        for (int i = 1; i <= e.tags.size(); i++) {
            String tagHierarchy = String.join(":", e.tags.subList(0, i));
            tagCountMap.put(tagHierarchy, tagCountMap.getOrDefault(tagHierarchy, 0) + 1);
        }
    }

    public synchronized void stopTracking(Integer id) {
        List<String> tags = entityMap.get(id);
        if (tags != null) {
            for (int i = 1; i <= tags.size(); i++) {
                String tagHierarchy = String.join(":", tags.subList(0, i));
                tagCountMap.put(tagHierarchy, tagCountMap.getOrDefault(tagHierarchy, 0) - 1);
            }
            entityMap.remove(id);
        }
    }

    // "The system is expected to give this count, as "fast" as possible"
    // Reason for Using Hashmap and precomputing all tags hierarchy
    public int getCounts(List<String> tags) {
        return countingStrategy.count(tagCountMap, tags);
    }

    public void setCountingStrategy(CountingStrategy strategy) {
        this.countingStrategy = strategy;
    }
}

public class PendencySystemClient {
    public static void main(String[] args) {
        // Singleton Instance for tracking
        PendencySystem system = PendencySystem.getInstance();

        // Test cases Present in Question
        system.startTracking(new Entity(1112, Arrays.asList("UPI", "Karnataka", "Bangalore")));
        system.startTracking(new Entity(2451, Arrays.asList("UPI", "Karnataka", "Mysore")));
        system.startTracking(new Entity(3421, Arrays.asList("UPI", "Rajasthan", "Jaipur")));
        system.startTracking(new Entity(1221, Arrays.asList("Wallet", "Karnataka", "Bangalore")));

        System.out.println(system.getCounts(Arrays.asList("UPI")));
        System.out.println(system.getCounts(Arrays.asList("UPI", "Karnataka")));
        System.out.println(system.getCounts(Arrays.asList("UPI", "Karnataka", "Bangalore")));
        System.out.println(system.getCounts(Arrays.asList("Bangalore")));

        system.startTracking(new Entity(4221, Arrays.asList("Wallet", "Karnataka", "Bangalore")));
        system.stopTracking(1112);
        system.stopTracking(2451);

        System.out.println(system.getCounts(Arrays.asList("UPI")));
        System.out.println(system.getCounts(Arrays.asList("Wallet")));
        System.out.println(system.getCounts(Arrays.asList("UPI", "Karnataka", "Bangalore")));
    }
}

/*
 * Reason for Singleton -> One object should be there across application and
 * thread safety
 * Intrinsic Locks: Locks are associated with objects, not code blocks or
 * methods.
 * This means synchronizing on the same object ensures thread-safe access to
 * synchronized blocks/methods for that object.
 */

/*
 * Why Hashmap ? -> to GetCount in O(1)
 * So basically we are precomputing
 */

// Why Concurrent HashMAP

/*
 * Key Features of ConcurrentHashMap: Scalable in multi-threaded scenarios.
 * Thread Safety: It ensures that multiple threads can safely access the map
 * without corrupting its state.
 * Segmented Locking: It uses a concept called bucket-level or segment-level
 * locking. Instead of locking the entire map during updates, only a segment (or
 * bucket) is locked, improving concurrency.
 * Non-Blocking Reads: Reads are generally lock-free, meaning they can proceed
 * without waiting for locks.
 * No Null Keys or Values: Unlike HashMap, ConcurrentHashMap does not allow null
 * keys or values to avoid ambiguities in concurrent scenarios.
 * High Performance: Due to its design, it provides better performance than
 * using a synchronized HashMap or manually synchronized blocks for
 * high-concurrency scenarios.
 * 
 */

/*
 * Why synchronized?: Synchronization ensures that changes made by one thread
 * are visible to others,
 * and prevents multiple threads from modifying the counts and entity map
 * simultaneously,
 * which could lead to inconsistent or incorrect results.
 */

/*
 * The getCounts method does not need to be synchronized because it only reads
 * from the tagCountMap,
 * which is a ConcurrentHashMap. Since ConcurrentHashMap supports thread-safe
 * reads and writes,
 * there's no risk of inconsistency while reading the counts.
 */

/*
 * Command Pattern can be used for commands like start track and stop tracking
 */

/*
 * HashMap:
 * Use when the number of unique hierarchical combinations is manageable.
 * Optimized for flat and frequent lookups.
 * Best for scenarios where memory is less constrained.
 * Trie:
 * Use for dynamic hierarchies or when there are many shared prefixes.
 * More memory-efficient for deeply hierarchical data.
 * Preferred for scenarios where hierarchy depth is variable or unknown in
 * advance.
 */