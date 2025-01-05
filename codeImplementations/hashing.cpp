#include <iostream>
#include <list>
#include <iterator>
#include <string>
using namespace std;

class HashTable {
private:
    int capacity; // Number of buckets
    list<pair<int, string>>* table; // Array of lists for chaining

public:
    // Constructor to initialize the hash table with a specific capacity
    HashTable(int cap) {
        capacity = cap;
        table = new list<pair<int, string>>[capacity];
    }

    // Hash function to compute the index for a given key
    int hash(int key) {
        return key % capacity;  // Simple modulo-based hash function
    }

    // Insert a key-value pair into the hash table
    void insert(int key, string value) {
        int index = hash(key);
        table[index].push_back(make_pair(key, value));  // Chaining with linked list
    }

    // Search for a value by key
    string search(int key) {
        int index = hash(key);
        for (auto& element : table[index]) {
            if (element.first == key) {
                return element.second;
            }
        }
        return "Not Found";  // Return a "Not Found" message if key is not present
    }

    // Delete a key-value pair from the hash table
    void deleteKey(int key) {
        int index = hash(key);
        list<pair<int, string>>& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    // Display the hash table contents
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            for (auto& element : table[i]) {
                cout << "(" << element.first << ", " << element.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(5);  // Create a hash table with 5 buckets

    ht.insert(1, "One");
    ht.insert(2, "Two");
    ht.insert(3, "Three");
    ht.insert(6, "Six");
    ht.insert(11, "Eleven");

    ht.display();  // Display the hash table

    cout << "Search for key 3: " << ht.search(3) << endl;  // Search for key 3
    cout << "Search for key 10: " << ht.search(10) << endl;  // Search for a non-existing key

    ht.deleteKey(6);  // Delete key 6
    ht.display();  // Display the hash table after deletion

    return 0;
}
