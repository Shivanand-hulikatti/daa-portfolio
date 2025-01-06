#include <iostream>
#include <vector>

class FenwickTree {
public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void update(int index, int delta) {
        while (index < tree.size()) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

private:
    std::vector<int> tree;
};

int main() {
    std::vector<int> data = {0, 3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3};
    FenwickTree fenwickTree(data.size());

    for (int i = 1; i < data.size(); ++i) {
        fenwickTree.update(i, data[i]);
    }

    std::cout << "Sum of first 5 elements: " << fenwickTree.query(5) << std::endl;
    std::cout << "Sum of elements from index 2 to 6: " << fenwickTree.query(6) - fenwickTree.query(1) << std::endl;

    return 0;
}