#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/*
In C++, set is an associative container that provides the implementation of
Red-Black Tree. This data structure makes sure that elements are always stored
in a sorted order. It also makes sure that insertion, deletion, and access
operations take logarithmic time.
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
void _print(set<T>& v) {
    cout << "{ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "}";
}

template <class T>
void _print(set<T, greater<T>>& v) {
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
        int arr[] = {2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7};
        set<int> st1;
        set<int, greater<int>> st2;

        // Insert elements
        cout << "arr : [ ";
        for (auto e : arr) {
            cout << e << " ";
            st1.insert(e);  // O(log(n)) time
            st2.insert(e);
        }
        cout << "]\n";
        // st(arr, arr + sizeof(arr) / sizeof(arr[0]));
        debug(st2);
        debug(st1);
        int len = st1.size();
        debug(len);

        // Erase elements
        st1.erase(st1.begin());  // st.erase(iterator)
        debug(st1);
        st1.erase(st1.find(5));  // st.erase(iterator)
        debug(st1);
        st1.erase(6);  // st.erase(value)
        debug(st1);
        st1.erase(st1.begin(), st1.find(7));  // st.erase(start, end) - range
        debug(st1);

        // Copy & find
        set<int> st3(st2.begin(), st2.end());
        set<int, greater<int>> st4 = st2;
        debug(st3);
        debug(st4);
        auto it = st3.find(6);
        debug(*it);
        auto itr = st3.find(9);
        debug(*itr);

        // Check if st1 is empty
        cout << "Is st1 empty? " << (st1.empty() ? "Yes" : "No") << endl;

        // Swapping two sets
        set<int> st5 = {1, 2, 3, 4, 5};
        set<int> st6 = {6, 7, 8, 9, 10};
        debug(st5);
        debug(st6);
        st5.swap(st6);
        debug(st5);
        debug(st6);

        // Comparator for custom sorting
        struct comp {
            bool operator()(const pii& p1, const pii& p2) const {
                return p1.second > p2.second;  // descending order by .second
            }
            // this comparator is used to sort the multiset in descending order
            // based on the second element of the pair, if the second element
            // is same then it will sort based on the first element of the pair
        };

        set<pii, comp> st7;
        st7.insert({1, 2});
        st7.insert({2, 1});
        st7.insert({3, 4});
        st7.insert({4, 3});
        st7.insert({5, 6});
        st7.insert({6, 5});
        st7.insert({7, 8});
        st7.insert({8, 7});
        for (auto i = st7.begin(); i != st7.end(); i++) {
            cout << i->first << " " << i->second << endl;
        }

        // clear the whole container
        st1.clear();
        debug(st1);
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
