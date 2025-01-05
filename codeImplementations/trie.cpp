#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure for the Trie
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

// Trie class
class Trie {
private:
    TrieNode* root;

    // Helper function for deletion
    bool deleteHelper(TrieNode* node, const string &word, int depth) {
        if (!node) return false;

        // If last character of word is being processed
        if (depth == word.size()) {
            // Word exists, mark end of word as false
            if (node->isEndOfWord) {
                node->isEndOfWord = false;

                // If node has no children, it can be deleted
                return node->children.empty();
            }
            return false;
        }

        char ch = word[depth];
        if (deleteHelper(node->children[ch], word, depth + 1)) {
            delete node->children[ch];
            node->children.erase(ch);

            // Return true if no children and not end of another word
            return node->children.empty() && !node->isEndOfWord;
        }
        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string &word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (!current->children[ch]) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const string &word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (!current->children[ch]) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    // Delete a word from the Trie
    void remove(const string &word) {
        deleteHelper(root, word, 0);
    }

    // Check if a prefix exists in the Trie
    bool startsWith(const string &prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (!current->children[ch]) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }
};

// Example usage
int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'bat': " << (trie.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Search 'ball': " << (trie.search("ball") ? "Found" : "Not Found") << endl;
    cout << "Starts with 'ba': " << (trie.startsWith("ba") ? "Yes" : "No") << endl;

    trie.remove("bat");
    cout << "Search 'bat' after removal: " << (trie.search("bat") ? "Found" : "Not Found") << endl;

    return 0;
}
