#include <bits/stdc++.h>
using namespace std;

/*
 * GENERATED WITH GITHUB COPILOT
 *
 * The split function takes a string and a character as input and splits the
 * string into substrings based on the character. It returns a vector of strings
 * containing the substrings.
 * The split_1 function is similar to split but handles consecutive delimiters
 * differently. It ensures that empty substrings are not included in the result.
 * The reverseWords function takes a string, splits it into words, and reverses
 * the order of the words in the string.
 */

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<string> split_1(string &s, const char &c) {
    int n = s.size(), l = 0, r = 0;
    s.push_back(c);
    vector<string> res;
    while (s[r] == c) r++;
    l = r;
    while (r < n) {
        while (s[r] != c) r++;
        string word = s.substr(l, r - l);
        if (!word.empty()) {
            res.push_back(word);
        }
        while (s[r] == c) r++;
        l = r;
    }
    return res;
}

// no s.push_back(c) in the function, so no mutating the original string
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<string> split_2(string &s, const char &c) {
    int n = s.size(), l = 0, r = 0;
    vector<string> res;
    while (r < n) {
        // Skip leading delimiters
        while (r < n && s[r] == c) r++;
        l = r;
        // Move r to next delimiter or end
        while (r < n && s[r] != c) r++;
        if (l < r) {
            res.push_back(s.substr(l, r - l));
        }
    }
    return res;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<string> split_3(string &s, const char &c) {
    int n = s.size(), l = 0, r = 0;
    s.push_back(c);
    vector<string> res;
    do {
        while (s[r] != c) r++;
        string word = s.substr(l, r - l);
        if (!word.empty()) {
            res.push_back(word);
        }
        while (r < n && s[r] == c) r++;
        l = r;
    } while (r < n);
    return res;
}

// no s.push_back(c) in the function, so no mutating the original string
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<string> split(const string &s, const char &c) {
    int n = s.size(), l = 0, r = 0;
    vector<string> res;
    if (n == 0) return res;  // handle empty string edge case
    do {
        while (r < n && s[r] != c) r++;
        if (l < r) {  // make sure we have a valid word
            res.push_back(s.substr(l, r - l));
        }
        while (r < n && s[r] == c) r++;
        l = r;
    } while (r < n);
    return res;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
string reverseWords(string &s) {
    vector<string> v = split(s, ' ');
    if (v.size() == 1) return s;
    string res = v.back();
    for (int i = v.size() - 2; i >= 0; i--) {
        res += " " + v[i];
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("zin.txt", "r", stdin);
    freopen("zout.txt", "w", stdout);
    freopen("zerr.txt", "w", stderr);
#endif
    string s = " Let's  ta+ke    Leet+Code contest   Tomorrow  ";
    string s1 = ",,Let's,,,take,,,,,,,Leet+Code,,contest,,,Tomorrow,,";
    string s2 = "Let's take LeetCode contest Tomorrow";
    vector<string> v = split(s, ' ');
    for (auto &x : v) cout << x << endl;
    cout << "------------------------" << endl;
    v = split(s1, ',');
    for (auto &x : v) cout << x << endl;
    cout << "------------------------" << endl;
    cout << reverseWords(s2) << endl;
    return 0;
}
