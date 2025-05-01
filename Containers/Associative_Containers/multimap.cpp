#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

/*
In C++, multimap is an associative container similar to map, but it can have
multiple elements with same keys. It stores all the elements in increasing order
based on their keys by default but can be changed if required. It provides fast
insertion, deletion and search on this sorted data.
*/

// Debug Module
#ifndef ONLINE_JUDGE
#define debug(x)         \
    cout << #x << " : "; \
    _print(x);           \
    cout << endl;
#endif
void _print(ll t) { cout << t; }
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(ld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }
template <class T, class V>
void _print(multimap<T, V> &m) {
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
        multimap<int, int> m1;
        multimap<int, int> m2;

        // Insert elements
        cout << "arr : [ ";
        for (auto e : arr) {
            cout << e << " ";
            m1.insert({e, e * e});  // O(log(n)) time
            m2.emplace(e, e * e);   // O(log(n)) time
        }
        cout << "]" << endl;
        debug(m1);
        debug(m2);

        // Accessing elements
        debug(m1.find(2)->first);
        debug(m1.find(2)->second);

        // Updating value
        m1.insert({2, 3});
        m1.insert({2, 5});
        debug(m1);

        // Frequency of a Key
        debug(m1.count(2));
        debug(m1.count(5));

        // Finding all occurrences of a specific key in a Multimap
        multimap<string, string> mp = {
            {"id", "111"},      {"id", "112"},        {"student", "John"},
            {"student", "Bob"}, {"student", "Alice"}, {"student", "Mike"}};

        debug(mp);
        string key = "student";
        auto range = mp.equal_range(key);

        // Printing all occurrences of the specific key
        cout << "Occurrences of the  key '" << key << "' are: " << endl;
        for (auto it = range.first; it != range.second; ++it) {
            cout << "Key: " << it->first << ", Value: " << it->second << endl;
        }

        // Erasing elements
        m1.erase(2);  // erase all occurrences of 2, O(log(n) + n) time
        debug(m1);

        m1.erase(m1.find(5), m1.find(7));  // erase 5 to before 7
        debug(m1);

        m1.erase(m1.begin(), m1.find(6));  // erase all elements before 6
        debug(m1);

        // Swapping two multimaps
        multimap<int, int> m3 = {{1, 1}, {2, 2}, {3, 3}};
        debug(m3);
        debug(m2);
        m3.swap(m2);
        debug(m3);
        debug(m2);

        // check if multimap is empty or not
        cout << "m1 is empty : " << (m1.empty() ? "Yes" : "No") << endl;
        cout << "m2 is empty : " << (m2.empty() ? "Yes" : "No") << endl;

        // size of the multimap
        cout << "Size of m1 : " << m1.size() << endl;
        cout << "Size of m2 : " << m2.size() << endl;

        // find an element in the multimap
        auto it = m1.find(5);  // O(log(n)) time
        cout << "Element found : " << (it != m1.end() ? "Yes" : "No") << endl;
        cout << "Element found : " << (m1.find(100) != m1.end() ? "Yes" : "No")
             << endl;

        // Convert a Vector of Pairs to a Multimap
        vector<pair<int, string>> v = {{1, "One"}, {2, "Two"}, {3, "Three"}};
        multimap<int, string> m4(v.begin(), v.end());
        debug(m4);

        // Map and External Sorting Criteria/Comparator
        // Sort a map by custom order
        struct cmp {
            bool operator()(int a, int b) const { return a > b; }
        };
        multimap<int, int> m5;
        multimap<int, int, cmp> m6;
        m5.insert({0, 51});
        m5.insert({1, 6});
        m5.insert({1, 60});
        m5.insert({2, 7});
        m5.insert({2, 70});
        m5.insert({3, 8});
        m5.insert({3, 80});
        m5.insert({4, 9});
        m6.insert({0, 51});
        debug(m5);
        cout << "m6 : [ ";
        for (auto &[k, v] : m6) {
            cout << "{" << k << ":" << v << "}";
            cout << " ";
        }
        cout << "]" << endl;

        // Merge two multimaps
        multimap<int, int> m7 = {{1, 1}, {2, 2}, {3, 3}};
        multimap<int, int> m8 = {{4, 4}, {5, 5}, {6, 6}};
        m7.merge(m8);  // only in c++17 and above
        debug(m7);     // m7 = m7 + m8
        debug(m8);     // m8 is now empty
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
    }
    return 0;
}
