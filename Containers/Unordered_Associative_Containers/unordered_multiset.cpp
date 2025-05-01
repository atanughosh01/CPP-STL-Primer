#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

/*
In C++, unordered multiset is an unordered associative container that works
similarly to an unordered set, but it can store multiple copies of the same
value. It provides fast insert, delete and search operations using hashing, but
the elements are not in any particular order.
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
template <class T>
void _print(unordered_multiset<T>& v) {
    cout << "[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

class Solution {
   public:
    void solve() {
        int arr[] = {9, 2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7, 7, 8};
        unordered_multiset<int> st1, st2;

        // Insert elements
        cout << "arr : [ ";
        for (auto e : arr) {
            cout << e << " ";
            st1.insert(e);
            st2.emplace(e * e);
        }
        cout << "]\n";
        debug(st1);
        debug(st2);
        auto len = st1.size();
        debug(len);

        // Erase elements
        st1.erase(2);
        debug(st1);
        auto it = st2.find(4);
        if (it != st2.end()) st2.erase(it);
        debug(st2);
        st2.erase(st2.begin());
        debug(st2);
        st2.erase(st2.find(4), st2.end());  // range erase
        debug(st2);

        // Copy and find
        unordered_multiset<int> st3(st2.begin(), st2.end());
        debug(st3);
        auto it2 = st3.find(4);
        cout << "st3.find(4) : " << (it2 != st3.end() ? *it2 : -1) << endl;
        auto it3 = st3.find(9);
        cout << "st3.find(9) : " << (it3 != st3.end() ? *it3 : -1) << endl;

        // check if set is empty
        cout << "st1 is empty : " << (st1.empty() ? "Yes" : "No") << endl;

        // Swap two multisets
        unordered_multiset<int> st4 = {10, 2, 32, -4, 5};
        unordered_multiset<int> st5 = {16, 71, 8, 96, -10};
        debug(st4);
        debug(st5);
        st4.swap(st5);
        debug(st4);
        debug(st5);

        // Custom hash function for unordered_multiset
        struct custom_hash {
            size_t operator()(const pair<int, int>& p) const {
                return hash<int>()(p.first) ^ hash<int>()(p.second);
            }
        };
        unordered_multiset<pair<int, int>, custom_hash> st6;
        st6.insert({1, 2});
        st6.insert({1, 20});
        st6.insert({2, 1});
        st6.insert({3, 4});
        st6.insert({3, 40});
        st6.insert({4, 3});
        st6.insert({5, 6});
        st6.insert({6, 5});
        st6.insert({7, 8});
        st6.insert({8, 7});
        for (auto i : st6) {
            cout << "(" << i.first << "," << i.second << ") ";
        }
        cout << endl;

        // Clear the multiset
        st6.clear();
        cout << "st6 is empty : " << (st6.empty() ? "Yes" : "No") << endl;
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
