#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/*
In C++, the unordered_multimap is an unordered associative container that stores
data in the form of key-value pairs. It is similar to unordered map, but it
allows multiple elements with the same key. It provides fast insertion, deletion
and search operations in O(1) time by using hashing.
*/

#define debug(x)         \
    cout << #x << " : "; \
    _print(x);           \
    cout << endl;
void _print(ll t) { cout << t; }
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(ld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }
template <class T, class V>
void _print(unordered_multimap<T, V> &m) {
    cout << "[ ";
    for (auto &[k, v] : m) {
        cout << "{" << k << ":" << v << "}";
        cout << " ";
    }
    cout << "]";
}

class Solution {
   public:
    void solve() {
        int arr[] = {2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7};
        unordered_multimap<int, int> m1;
        unordered_multimap<int, string> m2;

        // Insert elements
        cout << "arr : [ ";
        for (auto e : arr) {
            cout << e << " ";
            m1.insert({e, e * e});
            m2.insert({e, to_string(e * e)});
        }
        cout << "]\n";
        debug(m1);
        debug(m2);

        // Accessing elements
        auto it = m1.find(5);
        cout << it->first << " " << it->second << endl;

        // Erase elements
        m1.erase(5);
        debug(m1);

        // Update elements
        auto it2 = m1.find(2);
        if (it2 != m1.end()) {
            it2->second = 10;  // Update the value associated with key 2
        } else {
            cout << "Key 2 not found" << endl;
        }
        debug(m1);

        // Swapping two maps
        unordered_multimap<int, string> m3 = {
            {1, "One"}, {2, "Two"}, {3, "One"}, {2, "Two Two"}};
        unordered_multimap<int, string> m4 = {
            {4, "Four"}, {5, "Five"}, {6, "Six"}};
        debug(m3);
        debug(m4);
        m3.swap(m4);
        debug(m3);
        debug(m4);

        // Check if map is empty
        cout << "m3 is empty : " << (m3.empty() ? "Yes" : "No") << endl;

        // Size of the map
        cout << "Size of m3 : " << m3.size() << endl;

        // Count the number of elements with a specific key
        cout << "Count of 2 in m3 : " << m3.count(2) << endl;

        // Convert a vector of pairs to an unordered_map
        vector<pair<int, string>> v = {{1, "One"}, {2, "Two"}, {3, "Three"}};
        unordered_multimap<int, string> m5(v.begin(), v.end());
        debug(m5);

        // Convert an unordered_map to a vector of pairs
        vector<pair<int, string>> v2(m5.begin(), m5.end());
        cout << "v2 : [ ";
        for (auto &[k, v] : v2) {
            cout << "{" << k << ":" << v << "}";
            cout << " ";
        }
        cout << "]" << endl;

        // Custom hash function
        struct custom_hash {
            size_t operator()(const pair<int, int> &p) const {
                return hash<int>()(p.first) ^ hash<int>()(p.second);
            }
            // This hash function is used to hash the pair of integers
            // by combining the hash values of the two integers using XOR.
            // This ensures that the hash value is unique for different pairs of
            // integers.
        };

        // You need to provide a custom hash function when declaring an
        // unordered_multimap with a key type of std::pair, because std::hash is
        // not defined for std::pair by default.
        unordered_multimap<pii, string, custom_hash> m6;
        m6.insert({{1, 2}, "OneTwo"});
        m6.insert({{3, 4}, "ThreeFour"});
        m6.insert({{5, 6}, "FiveSix"});
        cout << "m6 : [ ";
        for (auto &[k, v] : m6) {
            cout << "{" << k.first << "," << k.second << ":" << v << "}";
            cout << " ";
        }
        cout << "]" << endl;

        // Merge two unordered_multimaps
        unordered_multimap<int, string> m7 = {
            {1, "One"}, {2, "Two"}, {3, "Three"}};
        unordered_multimap<int, string> m8 = {
            {4, "Four"}, {5, "Five"}, {6, "Six"}};
        debug(m7);
        debug(m8);
        m7.insert(m8.begin(), m8.end());
        debug(m7);
        debug(m8);

        // Clear the map
        m1.clear();
        cout << "m1 is empty : " << (m1.empty() ? "Yes" : "No") << endl;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("zin.txt", "r", stdin);
    freopen("zout.txt", "w", stdout);
    freopen("zerr.txt", "w", stderr);
#endif
    int T = 1;
    // cin >> T;
    while (T--) {
        Solution obj;
        obj.solve();
        cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs\n";
    }
    return 0;
}
