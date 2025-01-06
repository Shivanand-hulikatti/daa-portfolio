#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an unordered_map to store key-value pairs
    std::unordered_map<std::string, int> hashMap;

    // Insert some key-value pairs into the hash map
    hashMap["apple"] = 1;
    hashMap["banana"] = 2;
    hashMap["cherry"] = 3;

    // Access and print values using keys
    std::cout << "apple: " << hashMap["apple"] << std::endl;
    std::cout << "banana: " << hashMap["banana"] << std::endl;
    std::cout << "cherry: " << hashMap["cherry"] << std::endl;

    // Check if a key exists in the hash map
    if (hashMap.find("date") != hashMap.end()) {
        std::cout << "date is in the hash map" << std::endl;
    } else {
        std::cout << "date is not in the hash map" << std::endl;
    }

    return 0;
}