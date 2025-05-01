#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/*
In C++, unordered_map is an unordered associative container that stores data in
the form of unique key-value pairs. But unlike map, unordered map stores its
elements using hashing. This provides average constant-time complexity O(1) for
search, insert, and delete operations but the elements are not sorted in any
particular order.
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
void _print(unordered_map<T, V> &m) {
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
        unordered_map<int, int> m1;
        unordered_map<int, string> m2;

        // Insert elements
        cout << "arr : [ ";
        for (auto e : arr) {
            cout << e << " ";
            m1[e]++;
            m2[e] = to_string(e * e);
        }
        cout << "]\n";
        debug(m1);
        debug(m2);

        // Insert elements
        m2.insert({4, "Four"});
        m2.insert({5, "Five"});
        debug(m2);
        m2[6] = "Six";  // O(1) time
        m2[7] = "Seven";
        debug(m2);

        // Accessing elements
        debug(m2[5]);  // O(1) time
        debug(m2[8]);

        // Erase elements
        m2.erase(5);  // O(1) time
        debug(m2);

        // Swapping two maps
        unordered_map<int, string> m3 = {{1, "One"}, {2, "On"}, {3, "One"}};
        unordered_map<int, string> m4 = {{4, "Four"}, {5, "Five"}, {6, "Six"}};
        debug(m3);
        debug(m4);
        m3.swap(m4);  // O(1) time
        debug(m3);
        debug(m4);

        // Check if map is empty
        cout << "m3 is empty : " << (m3.empty() ? "Yes" : "No") << endl;

        // Size of the map
        cout << "Size of m3 : " << m3.size() << endl;

        // Find an element in the map
        auto it = m3.find(5);  // O(1) time
        cout << "Element found : " << (it != m3.end() ? "Yes" : "No") << endl;

        // Count the number of elements with a specific key
        cout << "Count of 2 in m3 : " << m3.count(2) << endl;

        // Convert a vector of pairs to an unordered_map
        vector<pair<int, string>> v = {{1, "One"}, {2, "Two"}, {3, "Three"}};
        unordered_map<int, string> m5(v.begin(), v.end());
        debug(m5);

        // Convert an unordered_map to a vector of pairs
        vector<pair<int, string>> v2(m5.begin(), m5.end());
        cout << "v2 : [ ";
        for (auto &[k, v] : v2) {
            cout << "{" << k << ":" << v << "}";
            cout << " ";
        }
        cout << "]" << endl;

        // hash function
        cout << "Hash function for 5 : " << m5.hash_function()(5) << endl;

        // bucket count
        cout << "Bucket count : " << m5.bucket_count() << endl;
        cout << "Max bucket count : " << m5.max_bucket_count() << endl;
        cout << "Load factor : " << m5.load_factor() << endl;
        cout << "Max load factor : " << m5.max_load_factor() << endl;
        cout << "Bucket size : " << m5.bucket_size(0) << endl;
        cout << "Bucket number of 5 : " << m5.bucket(5) << endl;

        // rehashing
        cout << "Rehashing...\n";
        m5.rehash(20);  // O(N) time
        cout << "Bucket count after rehashing : " << m5.bucket_count() << endl;
        cout << "Max bucket count after rehashing : " << m5.max_bucket_count()
             << endl;
        cout << "Load factor after rehashing : " << m5.load_factor() << endl;
        cout << "Max load factor after rehashing : " << m5.max_load_factor()
             << endl;
        cout << "Bucket size after rehashing : " << m5.bucket_size(0) << endl;

        // Custom hash function
        struct custom_hash {
            size_t operator()(const pair<int, int> &p) const {
                return hash<int>()(p.first) ^ hash<int>()(p.second);
            }
        };
        unordered_map<pair<int, int>, string, custom_hash> m6;
        m6[make_pair(1, 2)] = "OneTwo";
        m6[make_pair(3, 4)] = "ThreeFour";
        m6[make_pair(5, 6)] = "FiveSix";
        cout << "m6 : [ ";
        for (auto &[k, v] : m6) {
            cout << "{" << k.first << "," << k.second << ":" << v << "}";
            cout << " ";
        }
        cout << "]" << endl;
        cout << "Hash function for (1, 2) : "
             << m6.hash_function()(make_pair(1, 2)) << endl;
        cout << "Hash function for (3, 4) : "
             << m6.hash_function()(make_pair(3, 4)) << endl;

        // Merge two unordered_maps
        unordered_map<int, string> m7 = {{1, "One"}, {2, "Two"}, {3, "Three"}};
        unordered_map<int, string> m8 = {{4, "Four"}, {5, "Five"}, {6, "Six"}};
        debug(m7);
        debug(m8);
        m7.insert(m8.begin(), m8.end());
        debug(m7);  // m7 = m7 + m8
        debug(m8);

        // clear the map
        m7.clear();
        debug(m7);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("zin.txt", "r", stdin);
    freopen("zout.txt", "w", stdout);
    freopen("zerr.txt", "w", stderr);
#endif
    int T = 1;
    cin >> T;
    while (T--) {
        Solution obj;
        obj.solve();
        cerr << "Time taken: " << (float)clock() / CLOCKS_PER_SEC << " secs\n";
    }
    return 0;
}
