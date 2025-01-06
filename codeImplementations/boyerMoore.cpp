#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void preprocessBadChar(const string &pattern, vector<int> &badChar) {
    int m = pattern.size();
    for (int i = 0; i < 256; i++) {
        badChar[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        badChar[(int)pattern[i]] = i;
    }
}

void boyerMooreSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> badChar(256);

    preprocessBadChar(pattern, badChar);

    int s = 0; // s is the shift of the pattern with respect to text
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            cout << "Pattern occurs at index " << s << endl;
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else {
            s += max(1, j - badChar[text[s + j]]);
        }
    }
}

int main() {
    string text = "ABAAABCD";
    string pattern = "ABC";
    boyerMooreSearch(text, pattern);
    return 0;
}