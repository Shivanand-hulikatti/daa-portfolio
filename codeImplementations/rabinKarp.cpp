#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int d = 256;  // Number of characters in the input alphabet (e.g., ASCII)
const int q = 101;  // A prime number for hashing (can be any large prime number)

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int i, j;
    int p = 0;  // Hash value for the pattern
    int t = 0;  // Hash value for the text
    int h = 1;

    // Calculate the value of h = d^(m-1) % q
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value of the pattern and the first window of the text
    for (i = 0; i < m; i++) {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    // Slide the pattern over the text one by one
    for (i = 0; i <= n - m; i++) {
        // Check if the hash values match
        if (p == t) {
            // If the hash values match, check the actual substring to avoid collision
            bool found = true;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate the hash value for the next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // We might get negative values of t, converting it to positive
            if (t < 0) {
                t = t + q;
            }
        }
    }
}

int main() {
    string text = "ABCCDABCCDAB";
    string pattern = "ABCC";

    rabinKarp(text, pattern);
    
    return 0;
}
