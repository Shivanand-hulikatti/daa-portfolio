#include <iostream>
#include <unordered_map>
#include <vector>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");

    std::cout << std::boolalpha;
    std::cout << "Search 'hello': " << trie.search("hello") << std::endl; // true
    std::cout << "Search 'hell': " << trie.search("hell") << std::endl;   // false
    std::cout << "Starts with 'hell': " << trie.startsWith("hell") << std::endl; // true
    std::cout << "Starts with 'worl': " << trie.startsWith("worl") << std::endl; // true
    std::cout << "Starts with 'word': " << trie.startsWith("word") << std::endl; // false

    return 0;
}