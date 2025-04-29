#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/*
In C++, multiset is an associative container similar to the set, but it can
store multiple elements with same value. It is sorted in increasing order by
default, but it can be changed to any desired order. It provides fast insertion,
deletion and search operations.
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
void _print(multiset<T>& v) {
    cout << "[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(multiset<T, greater<T>>& v) {
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
        int arr[] = {2, 5, 2, 1, 5, 5, 2, 2, 1, 6, 6, 7, 7, 8};
        multiset<int> st1;
        multiset<int, greater<int>> st2;
        multiset<int> st3;

        // Insert elements
        cout << "arr : [ ";
        for (auto e : arr) {
            cout << e << " ";
            st1.insert(e);
            st2.insert(e);   // O(log(n)) time
            st3.emplace(e);  // O(log(n)) time
        }
        cout << "]\n";
        debug(st1);
        debug(st2);
        debug(st3);
        auto len = st1.size();
        debug(len);

        // erases specific elements
        st1.erase(2);
        debug(st1);
        auto it = st2.find(5);  // iterator pointing to the first occurance of 5
        st2.erase(it);  // deletes only that element to which the iterator is
                        // pointing to
        debug(st2);
        st2.erase(5);  // deletes all the occurances of 5 from the multiset
        debug(st2);
        debug(st1);

        // clears the whole container
        st3.clear();
        debug(st3);
        st2.erase(st2.begin(), st2.end());
        debug(st2);

        // Copy
        multiset<int, greater<int>> st4(st1.begin(), st1.end());
        multiset<int> st5 = st1;
        debug(st4);
        debug(st5);

        auto it1 = st4.find(6);
        debug(*it1);
        auto it2 = st4.find(9);
        debug(*it2);

        // check if multiset is empty or not
        cout << "st1 is empty : " << (st1.empty() ? "Yes" : "No") << endl;
        cout << "st2 is empty : " << (st2.empty() ? "Yes" : "No") << endl;

        // swapping two multisets
        multiset<int> st6 = {1, 2, 2, 3, 3, 4, 5};
        multiset<int> st7 = {6, 7, 7, 8, 8, 9, 10, 10, 11, 12};
        debug(st6);
        debug(st7);
        st6.swap(st7);
        debug(st6);
        debug(st7);

        // counting the number of occurances of an element
        cout << "Count of 2 in st1 : " << st1.count(2) << endl;
        cout << "Count of 5 in st1 : " << st1.count(5) << endl;

        // counting the number of occurances of an element in a range
        auto range = st1.equal_range(2);  // returns a pair of iterators
        // first iterator points to the first occurance of 2 and second iterator
        // points to the first occurance of 3
        cout << "Count of 2 in st1 : " << distance(range.first, range.second)
             << endl;
        cout << "Count of 5 in st1 : "
             << distance(st1.lower_bound(5),
                         st1.upper_bound(5))
             << endl;  // returns the number of occurances of 5 in st1

        // Comparator for custom sorting
        struct comp {
            bool operator()(const pii& p1, const pii& p2) const {
                return p1.second > p2.second;  // descending order by .second
            }
            // this comparator is used to sort the multiset in descending order
            // based on the second element of the pair, if the second element
            // is same then it will sort based on the first element of the pair
        };

        multiset<pii, comp> st8;
        st8.insert({1, 2});
        st8.insert({3, 2});
        st8.insert({2, 1});
        st8.insert({3, 4});
        st8.insert({4, 3});
        st8.insert({5, 3});
        st8.insert({4, 3});
        st8.insert({5, 6});
        st8.insert({6, 5});
        st8.insert({7, 8});
        st8.insert({7, 5});
        st8.insert({9, 8});
        st8.insert({7, 8});
        st8.insert({8, 7});
        for (auto i = st8.begin(); i != st8.end(); i++) {
            cout << "(" << i->first << "," << i->second << ")" << " ";
        }
        cout << endl << "st8 size : " << st8.size() << endl;
        cout << "st8 max size : " << st8.max_size() << endl;
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
