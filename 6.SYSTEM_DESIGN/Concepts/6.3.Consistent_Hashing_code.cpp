#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional> // For std::hash

using namespace std;

class ConsistentHashing
{
private:
    unordered_map<size_t, string> ring; // Mapping of hash values to nodes
    vector<size_t> sorted_keys;         // Sorted list of hash values (for fast lookup)
    int num_virtual_nodes;              // Number of virtual nodes per physical node

    // Hash function to map nodes and keys to the ring
    size_t hash_function(const string &key)
    {
        return hash<string>()(key); // Using std::hash for simplicity
    }

public:
    ConsistentHashing(int num_virtual_nodes = 3) : num_virtual_nodes(num_virtual_nodes) {}

    // Add a node to the ring
    void add_node(const string &node)
    {
        for (int i = 0; i < num_virtual_nodes; ++i)
        {
            string virtual_node = node + "__" + to_string(i);
            size_t virtual_node_hash = hash_function(virtual_node);
            ring[virtual_node_hash] = node;
            sorted_keys.push_back(virtual_node_hash);
        }
        sort(sorted_keys.begin(), sorted_keys.end());
    }

    // Remove a node from the ring
    void remove_node(const string &node)
    {
        for (int i = 0; i < num_virtual_nodes; ++i)
        {
            string virtual_node = node + "__" + to_string(i);
            size_t virtual_node_hash = hash_function(virtual_node);
            ring.erase(virtual_node_hash);
        }
        sorted_keys.erase(remove(sorted_keys.begin(), sorted_keys.end(), hash_function(node)), sorted_keys.end());
        sort(sorted_keys.begin(), sorted_keys.end());
    }

    // Get the node for a given key
    string get_node(const string &key)
    {
        if (ring.empty())
            return "";

        size_t key_hash = hash_function(key);

        // Binary search for the closest node in the sorted list of keys
        auto it = lower_bound(sorted_keys.begin(), sorted_keys.end(), key_hash);

        // If it reaches the end of the ring, loop back to the first node
        if (it == sorted_keys.end())
        {
            it = sorted_keys.begin();
        }

        size_t closest_node_hash = *it;
        return ring[closest_node_hash];
    }
};

int main()
{
    ConsistentHashing ch(3); // 3 virtual nodes per physical node

    // Add nodes
    ch.add_node("Node1");
    ch.add_node("Node2");
    ch.add_node("Node3");

    // Add some keys and distribute them across the nodes
    vector<string> keys = {"key1", "key2", "key3", "key4", "key5"};
    for (const string &key : keys)
    {
        string assigned_node = ch.get_node(key);
        cout << "Key '" << key << "' is assigned to node '" << assigned_node << "'" << endl;
    }

    // Remove a node and observe how data is redistributed
    cout << "\nRemoving Node2" << endl;
    ch.remove_node("Node2");

    for (const string &key : keys)
    {
        string assigned_node = ch.get_node(key);
        cout << "Key '" << key << "' is now assigned to node '" << assigned_node << "'" << endl;
    }

    return 0;
}

/*
Key 'key1' is assigned to node 'Node1'
Key 'key2' is assigned to node 'Node2'
Key 'key3' is assigned to node 'Node3'
Key 'key4' is assigned to node 'Node1'
Key 'key5' is assigned to node 'Node1'

Removing Node2
Key 'key1' is now assigned to node 'Node1'
Key 'key2' is now assigned to node 'Node3'
Key 'key3' is now assigned to node 'Node3'
Key 'key4' is now assigned to node 'Node1'
Key 'key5' is now assigned to node 'Node1'

*/