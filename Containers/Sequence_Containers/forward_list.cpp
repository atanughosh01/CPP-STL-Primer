#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

/*
In C++, forward_list container provides the implementation of singly linked list
data structure. It stores data in non-contiguous memory where each element
points to the next element in the sequence. This makes insertion and deletion
faster once the position of the element is known.
*/

class Solution {
   private:
#define printFList(x)   \
    cout << #x << ": "; \
    _print(x);          \
    cout << endl;
    void _print(int t) { cout << t; }
    template <class T>
    void _print(forward_list<T> l) {
        cout << "[ ";
        for (T i : l) {
            _print(i);
            cout << " ";
        }
        cout << "]";
    }

   public:
    void solve() {
        // Initializing a forward_list
        forward_list<int> fl = {1, 3, 2, 8, 9};
        printFList(fl);

        // Inserting elements
        fl.push_front(200);  // Insert at the front
        printFList(fl);

        // Inserting an element at a specific position
        auto it = fl.begin();
        advance(it, 3);
        fl.insert_after(it, 100);  // Insert 100 after index=3 (position 4)
        printFList(fl);

        // Deleting elements
        fl.remove(100);  // Remove all occurrences of 100
        printFList(fl);

        fl.sort();  // Sort the list
        printFList(fl);
        fl.sort(greater<int>());  // Sort in descending order
        printFList(fl);

        // Deleting an element at a specific position
        it = fl.begin();
        advance(it, 2);
        fl.erase_after(it);  // Remove element after index=2 (position 3)
        printFList(fl);

        // Reversing the list
        fl.reverse();
        printFList(fl);

        // Accessing elements in a forward_list
        cout << "First element: " << fl.front() << endl;
        cout << "Fourth element: " << *next(fl.begin(), 3) << endl;

        // Finding an element in the forward_list
        cout << "200: " << *find(fl.begin(), fl.end(), 200) << endl;
        // cout << "1000: " << *find(fl.begin(), fl.end(), 1000) << endl;

        // Check if forward_list is empty
        cout << "Empty? " << fl.empty() << endl;
        cout << "Size of flist = " << distance(fl.begin(), fl.end()) << endl;
        cout << "MAx Size of flist = " << fl.max_size() << endl;

        // Initializing a forward_list with a specific size and value
        forward_list<int> fl1(5);  // 5 elements initialized to 0
        forward_list<int> fl2(5, 42);
        printFList(fl1);
        printFList(fl2);

        // Copy a forward_list into another
        forward_list<int> fl3(fl.begin(), fl.end());  // copy constructor
        printFList(fl3);

        forward_list<int> fl4(fl);  // copy assignment operator
        printFList(fl4);

        // Assigning a forward_list to another
        forward_list<int> fl5;
        fl5.assign(fl.begin(), fl.end());  // assign function
        printFList(fl5);

        // Swapping two forward_lists
        cout << "Before swapping:" << endl;
        printFList(fl1);
        printFList(fl2);
        fl1.swap(fl2);  // swap function
        cout << "After swapping:" << endl;
        printFList(fl1);
        printFList(fl2);

        // Merging two forward_lists
        forward_list<int> fl6 = {1, 3, 5};
        forward_list<int> fl7 = {2, 4, 6};
        fl6.merge(fl7);  // Merge fl7 into fl6
        printFList(fl6);
        printFList(fl7);                 // fl7 is now empty
        fl6.merge(fl7, greater<int>());  // Merge in descending order
        printFList(fl6);
        printFList(fl7);  // fl7 is still empty

        // Splicing two forward_lists
        forward_list<int> fl8 = {1, 2, 3};
        forward_list<int> fl9 = {4, 5, 6};
        fl8.splice_after(fl8.begin(), fl9);  // Move elements from fl9 to fl8
        printFList(fl8);  // fl8 now contains elements from fl9
        printFList(fl9);  // fl9 is now empty
        fl8.splice_after(fl8.begin(), fl9, fl9.begin(),
                         fl9.end());  // Move elements from fl9 to fl8
        printFList(fl8);              // fl8 now contains elements from fl9
        printFList(fl9);              // fl9 is still empty

        // Clear the forward_list
        fl.clear();
        cout << "Size of flist: " << distance(fl.begin(), fl.end()) << endl;
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
