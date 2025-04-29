#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, string> pis;

/*
In C++, maps are associative containers that store data in the form of key value
pairs sorted on the basis of keys. No two mapped values can have the same keys.
By default, it stores data in ascending order of the keys, but this can be
changes as per requirement.
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
void _print(map<T, V> &m) {
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
        // create a map from an array
        map<int, int> m1;
        int arr[] = {2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7, 7, 8};
        for (auto &e : arr) m1[e]++;
        debug(m1);

        // Initialze map with list
        map<int, string> m2 = {{1, "One"}, {2, "On"}, {3, "One"}};
        debug(m2);

        // Insert elements
        m2.insert({4, "Four"});
        m2.insert({5, "Five"});
        debug(m2);
        m2[6] = "Six";  // O(log(n)) time
        m2[7] = "Seven";
        debug(m2);

        // Accessing elements
        debug(m2[1]);  // O(log(n)) time
        debug(m2[6]);

        // Updating value
        m2[1] = "Tweaks";
        m2.at(7) = "By";
        debug(m2);

        // Erasing elements
        m2.erase(1);  // single erase O(log(n)) time
        debug(m2);
        m2.erase(m2.find(5), m2.find(7));  // range erase 5 to 7, O(log(n)) time
        debug(m2);

        // Swapping two maps
        map<int, string> m3 = {{1, "One"}, {2, "On"}, {3, "One"}};
        debug(m3);
        m3.swap(m2);
        debug(m3);
        debug(m2);

        // check if map is empty or not
        cout << "m1 is empty : " << (m1.empty() ? "Yes" : "No") << endl;

        // size of the map
        cout << "Size of m1 : " << m1.size() << endl;

        // find an element in the map
        auto it = m1.find(5);  // O(log(n)) time
        cout << "Element found : " << (it != m1.end() ? "Yes" : "No") << endl;

        // count the number of occurances of an element
        cout << "Count of 2 in m1 : " << m1.count(2) << endl;

        // Convert a Vector of Pairs to a Map - O(NlogN)
        vector<pair<int, string>> v = {{1, "One"}, {2, "Two"}, {3, "Three"}};
        map<int, string> m4(v.begin(), v.end());
        debug(m4);

        // Convert a Map to a Vector of Pairs - O(NlogN),
        vector<pair<int, string>> v2(m4.begin(), m4.end());
        cout << "v2 : [ ";
        for (auto &[k, v] : v2) {
            cout << "{" << k << ":" << v << "}";
            cout << " ";
        }
        cout << "]" << endl;

        // Map and External Sorting Criteria/Comparator
        // Sort a map by custom order
        struct cmp {
            bool operator()(int a, int b) const { return a > b; }
        };
        map<int, int> m5;
        map<int, int, cmp> m6;
        m5[0] = 5;
        m5[1] = 6;
        m5[2] = 7;
        m5[3] = 8;
        m5[4] = 9;
        m6[0] = 5;
        m6[1] = 6;
        m6[2] = 7;
        m6[3] = 8;
        m6[4] = 9;
        debug(m5);
        cout << "m6 : [ ";
        for (auto &[k, v] : m6) {
            cout << "{" << k << ":" << v << "}";
            cout << " ";
        }
        cout << "]" << endl;

        // Merge two maps
        map<int, string> m7 = {{1, "One"}, {2, "On"}, {3, "One"}};
        map<int, string> m8 = {{4, "Four"}, {5, "Five"}, {6, "Six"}};
        debug(m7);
        debug(m8);
        m7.insert(m8.begin(), m8.end());  // O(NlogN) time
        debug(m7);                        // m7 = m7 + m8;

        // lower_bound and upper_bound
        // lower_bound - returns the first element which is greater than or
        // equal to the given value
        // upper_bound - returns the first element which is greater than the
        // given value
        auto it1 = m7.lower_bound(2);
        auto it2 = m7.upper_bound(2);
        cout << "lower_bound(2) : {" << it1->first << " : " << it1->second
             << "}\n";
        cout << "upper_bound(2) : {" << it2->first << " : " << it2->second
             << "}\n";
        cout << "lower_bound(5) : {" << m7.lower_bound(5)->first << " : "
             << m7.lower_bound(5)->second << "}\n";
        cout << "upper_bound(5) : {" << m7.upper_bound(5)->first << " : "
             << m7.upper_bound(5)->second << "}\n";

        // equal_range - returns a pair of iterators which points to the first
        // element which is greater than or equal to the given value and the
        // first element which is greater than the given value
        auto range = m7.equal_range(2);  // {lower_bound(2), upper_bound(2)}
        cout << "equal_range(2) : {" << range.first->first << " : "
             << range.first->second << "} - {" << range.second->first << " : "
             << range.second->second << "}\n";
        cout << "equal_range(5) : {" << m7.equal_range(5).first->first << " : "
             << m7.equal_range(5).first->second << "} - {"
             << m7.equal_range(5).second->first << " : "
             << m7.equal_range(5).second->second << "}\n";

        // clear the map
        m7.clear();
        cout << "m7 is empty : " << (m7.empty() ? "Yes" : "No") << endl;
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
