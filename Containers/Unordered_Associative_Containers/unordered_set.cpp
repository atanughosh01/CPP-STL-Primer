#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

/*
In C++, unordered_set is an unordered associative container that stores unique
elements. Unlike set, it stores its elements using hashing. This provides
average constant-time O(1) search, insert, and delete operations but the
elements are not sorted in any particular order.
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

template <class T>
void _print(unordered_set<T> v) {
    cout << "{ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "}";
}

class Solution {
   public:
    void solve() {
        int arr[] = {2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7, 7, 8};
        unordered_set<int> st1, st2;

        // Insert elements
        cout << "arr : [ ";
        for (auto e : arr) {
            cout << e << " ";
            st1.insert(e);       // O(1) time
            st2.emplace(e * e);  // O(1) time
        }
        cout << "]\n";
        debug(st1);
        debug(st2);
        int len = st1.size();
        debug(len);

        // Erase elements
        st1.erase(st1.begin());
        debug(st1);
        st1.erase(st1.find(5));  // st.erase(iterator)
        debug(st1);
        st1.erase(6);  // st.erase(value)
        debug(st1);
        st1.erase(st1.begin(), st1.find(7));  // st.erase(startItr, endItr)
        debug(st1);

        // Copy and find
        unordered_set<int> st3(st2.begin(), st2.end());
        debug(st3);
        auto it = st3.find(64);
        cout << "st3.find(64) : " << (it != st3.end() ? *it : -1) << endl;
        auto itr = st3.find(9);
        cout << "st3.find(9) : " << (itr != st3.end() ? *itr : -1) << endl;

        // Check if st1 is empty
        cout << "Is st1 empty? " << (st1.empty() ? "Yes" : "No") << endl;

        // Swapping two sets
        unordered_set<int> st4 = {10, 2, 32, -4, 5};
        unordered_set<int> st5 = {16, 71, 8, 96, -10};
        debug(st4);
        debug(st5);
        st4.swap(st5);
        debug(st4);
        debug(st5);

        // Custom hash function
        struct pair_hash {
            size_t operator()(const pii& p) const {
                return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
            }
            // This hasher function is used to generate a unique hash value for
            // a pair of integers. It combines the hash values of the two
            // integers using XOR and bitwise shift operations. This ensures
            // that the hash value is unique for different pairs of integers.
        };

        // Custom equality function
        struct pair_equal {
            bool operator()(const pii& a, const pii& b) const {
                return a.first == b.first && a.second == b.second;
            }
            // This equality function is used to compare two pairs of integers
            // for equality. It checks if both the first and second elements of
            // the pairs are equal.
        };

        unordered_set<pii, pair_hash, pair_equal> st6;
        st6.insert({1, 2});
        st6.insert({2, 1});
        st6.insert({3, 4});
        st6.insert({4, 3});
        st6.insert({5, 6});
        st6.insert({6, 5});
        st6.insert({7, 8});
        st6.insert({8, 7});

        for (const auto& p : st6) {
            cout << p.first << " " << p.second << endl;
        }

        // Clear the set
        st1.clear();
        cout << "st1 is empty : " << (st1.empty() ? "Yes" : "No") << endl;
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
