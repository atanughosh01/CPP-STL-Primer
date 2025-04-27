#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

/*
In C++, list container implements a DOUBLY LINKED LIST in which each element
contains the address of next and previous element in the list. It stores data in
non-contiguous memory, hence providing fast insertion and deletion once the
position of the element is known.
*/

class Solution {
   private:
#define printList(x)    \
    cout << #x << ": "; \
    _print(x);          \
    cout << endl;
    void _print(int t) { cout << t; }
    template <class T>
    void _print(list<T> l) {
        cout << "[ ";
        for (T i : l) {
            _print(i);
            cout << " ";
        }
        cout << "]";
    }

    //     void printList(list<int>& l) {
    //         cout << "List : ";
    //         for (auto it : l) {
    //             cout << it << " ";
    //         }
    //         cout << endl;
    //     }

   public:
    void solve() {
        // Initializing a list
        list<int> l = {1, 3, 2, 8, 9};
        printList(l);

        // Inserting elements
        l.push_back(500);   // emplace_back(500);
        l.push_front(200);  // emplace_front(200);

        // Inserting an element at a specific position
        auto it = l.begin();
        advance(it, 3);
        l.insert(it, 100);  // Insert 100 at index=3 (position 4)
        printList(l);

        // Sorting the list
        l.sort();
        printList(l);
        l.sort(greater<int>());  // Sort in descending order
        printList(l);

        // Deleteing elements
        l.pop_back();   // Remove last element
        l.pop_front();  // Remove first element

        // Deleting an element at a specific position
        it = l.begin();
        advance(it, 2);
        l.erase(it);  // Remove element at index=2 (position 3)
        printList(l);

        // Reversing the list
        l.reverse();
        printList(l);

        // Accessing elements in a list
        cout << "First element: " << l.front() << endl;  // First element
        cout << "Last element: " << l.back() << endl;    // Last element

        // Access fourth element (index 3)
        cout << "Fourth element: " << *next(l.begin(), 3) << endl;

        // finding an element in the list
        cout << "Size of the list = " << l.size() << endl;
        l.resize(10);
        printList(l);
        cout << "Size of the list = " << l.size() << endl;
        l.resize(15, 50);
        printList(l);
        cout << "Size of the list = " << l.size() << endl;
        cout << *find(l.begin(), l.end(), 100) << endl;   // returns 100
        cout << *find(l.begin(), l.end(), 2000) << endl;  // returns l.end()

        // Initializing a list
        list<int> l1(5);
        list<int> l2(8, 9);
        list<int> l3;
        printList(l1);
        printList(l2);
        printList(l3);

        // Check if list is empty
        cout << l1.empty() << endl;
        cout << l2.empty() << endl;
        cout << l3.empty() << endl;

        // Copy a list into another
        list<int> l4(l.begin(), l.end());  // copy constructor
        printList(l4);

        list<int> l5(l);  // copy assignment operator
        printList(l5);

        // Assigning a list to another
        list<int> l6;
        l6.assign(l.begin(), l.end());  // assign function
        printList(l6);

        // Reverse assign a list into another
        l6.assign(l.rbegin(), l.rend());
        printList(l6);

        // Swapping two lists
        cout << "Before swapping:" << endl;
        printList(l1);
        printList(l2);
        swap(l1, l2);
        cout << "After swapping:" << endl;
        printList(l1);
        printList(l2);

        // Merging two lists
        list<int> l7 = {1, 2, 3};
        list<int> l8 = {4, 5, 6};
        l7.merge(l8);   // Merge l8 into l7
        printList(l7);  // l7 = l7 + l8
        printList(l8);  // l8 is now empty

        // Splicing two lists
        list<int> l9 = {10, 20, 30};
        list<int> l10 = {40, 50, 60};
        auto it1 = l9.begin();
        advance(it1, 1);  // Point to the second element of l9
        auto it2 = l10.begin();
        advance(it2, 1);           // Point to the second element of l10
        l9.splice(it1, l10, it2);  // Move element from l10 to l9
        printList(l9);
        printList(l10);  // Element at pos 2 of l10 is moved to pos 2 of l9

        // Clear the list
        l.clear();
        cout << "Size of the list : " << l.size() << endl;
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
    }
    return 0;
}
