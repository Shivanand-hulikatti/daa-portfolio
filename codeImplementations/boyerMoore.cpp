#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to create the bad character table
void badCharTable(const string &pattern, vector<int> &badChar) {
    int m = pattern.length();
    fill(badChar.begin(), badChar.end(), -1);

    for (int i = 0; i < m; i++) {
        badChar[pattern[i]] = i;
    }
}

// Function to create the good suffix table
void goodSuffixTable(const string &pattern, vector<int> &goodSuffix) {
    int m = pattern.length();
    vector<int> border(m + 1, 0);
    goodSuffix.resize(m + 1, m);

    // Preprocessing to find the borders
    int i = m, j = m + 1;
    border[i] = j;

    while (i > 0) {
        while (j <= m && pattern[i - 1] != pattern[j - 1]) {
            if (goodSuffix[j] == m) {
                goodSuffix[j] = j - i;
            }
            j = border[j];
        }
        i--;
        j--;
        border[i] = j;
    }

    // Setting good suffix shifts
    j = border[0];
    for (i = 0; i <= m; i++) {
        if (goodSuffix[i] == m) {
            goodSuffix[i] = j;
        }
        if (i == j) {
            j = border[j];
        }
    }
}

// Boyer-Moore search function
void boyerMooreSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    // Create bad character and good suffix tables
    vector<int> badChar(256, -1);
    vector<int> goodSuffix;

    badCharTable(pattern, badChar);
    goodSuffixTable(pattern, goodSuffix);

    int s = 0; // Shift of the pattern with respect to the text

    while (s <= (n - m)) {
        int j = m - 1;

        // Decrease j while characters of pattern and text match
        while (j 
