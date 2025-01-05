#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> BIT;
    int n;

public:
    // Constructor: Initializes the Fenwick Tree with size n
    FenwickTree(int size) {
        n = size;
        BIT.resize(n + 1, 0);  // Create a BIT array of size n + 1, all initialized to 0
    }

    // Update operation: Add value 'val' to the element at index 'idx'
    void update(int idx, int val) {
        while (idx <= n) {
            BIT[idx] += val;  // Add val to the current index in BIT
            idx += idx & (-idx);  // Move to the next index (upward in the tree)
        }
    }

    // Query operation: Returns the sum of elements from index 1 to 'idx'
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += BIT[idx];  // Add the current index's value to the sum
            idx -= idx & (-idx);  // Move to the parent index
        }
        return sum;
    }

    // Range Query: Returns the sum of elements from index 'l' to 'r'
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    // Example usage:
    FenwickTree fenwick(10);  // Initialize a Fenwick Tree for an array of size 10

    // Update the Fenwick Tree with some values
    fenwick.update(1, 3);  // arr[1] += 3
    fenwick.update(2, 2);  // arr[2] += 2
    fenwick.update(3, 5);  // arr[3] += 5
    fenwick.update(4, 7);  // arr[4] += 7
    fenwick.update(5, 6);  // arr[5] += 6

    // Query for the sum of elements from index 1 to 5
    cout << "Sum of elements from index 1 to 5: " << fenwick.query(5) << endl;  // Output: 23

    // Range query: Sum from index 2 to 4
    cout << "Sum of elements from index 2 to 4: " << fenwick.rangeQuery(2, 4) << endl;  // Output: 14

    return 0;
}
