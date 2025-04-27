#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

/*
In C++, deque Stands for Double Ended QUEue, it is a special type of queue where
insertion and deletion operations are possible at both the ends in constant time
complexity. It is implemented as a dynamic array, which means that it can grow
and shrink in size as needed. Deque is a sequence container that allows fast
insertion and deletion at both ends. It is similar to a vector, but it allows
for more efficient insertion and deletion at both ends.
*/

class Solution {
   private:
#define printDq(x)      \
    cout << #x << ": "; \
    _print(x);          \
    cout << endl;
    void _print(int t) { cout << t; }
    template <class T>
    void _print(deque<T> dq) {
        cout << "[ ";
        for (T i : dq) {
            _print(i);
            cout << " ";
        }
        cout << "]";
    }

   public:
    void solve() {
        // Initializing a deque
        deque<int> dq = {1, 3, 2, 8, 9};
        printDq(dq);

        // Inserting elements
        dq.push_back(500);
        dq.push_front(200);

        // Inserting an element at a specific position
        auto itr = dq.begin();
        advance(itr, 3);
        dq.insert(itr, 100);
        printDq(dq);

        // Sorting the deque
        sort(dq.begin(), dq.end());
        printDq(dq);
        sort(dq.begin(), dq.end(), greater<int>());  // Sort in descending order
        printDq(dq);

        // Deleting elements
        dq.pop_back();                         // Remove last element
        dq.pop_front();                        // Remove first element
        dq.erase(dq.begin(), dq.begin() + 2);  // Remove first two elements
        printDq(dq);

        // Deleting an element at a specific position
        itr = dq.begin();
        advance(itr, 2);
        dq.erase(itr);  // Remove element at index=2 (position 3)
        printDq(dq);

        // Accessing elements in a deque
        cout << "First element: " << dq.front() << endl;  // First element
        cout << "Last element: " << dq.back() << endl;    // Last element

        // Access fourth element (index 3)
        cout << "Fourth element: " << dq[3] << endl;
        cout << "Fourth element: " << *next(dq.begin(), 3) << endl;

        // finding an element in the deque
        cout << "Size of the deque = " << dq.size() << endl;
        dq.resize(10);
        printDq(dq);
        cout << "Size of the deque = " << dq.size() << endl;
        dq.resize(15, 50);
        printDq(dq);
        cout << "Size of the deque = " << dq.size() << endl;
        cout << *find(dq.begin(), dq.end(), 50) << endl;
        cout << *find(dq.begin(), dq.end(), 2000) << endl;

        // Different Ways to Copy a Deque
        deque<int> oldDeque = {1, 2, 3, 4, 5};
        deque<int> newDeque(oldDeque.size());
        printDq(newDeque);
        printDq(oldDeque);
        // Copying Deque Using copy algorithm
        copy(oldDeque.begin(), oldDeque.end(), newDeque.begin());
        printDq(newDeque);
        printDq(oldDeque);

        deque<int> dq1(dq.begin(), dq.end());  // copy constructor
        printDq(dq1);
        deque<int> dq2(dq);  // copy assignment operator
        printDq(dq2);
        deque<int> dq3;
        dq3.assign(dq.begin(), dq.end());  // assign function
        printDq(dq3);
        dq3.assign(dq.rbegin(), dq.rend());  // reverse assign function
        printDq(dq3);

        // Swap Two Deque
        deque<int> dq4 = {1, 2, 3, 4, 5};
        deque<int> dq5 = {6, 7, 8, 9, 10};
        printDq(dq4);
        printDq(dq5);
        dq4.swap(dq5);  // Swap the contents of dq4 and dq5
        printDq(dq4);
        printDq(dq5);
        // Swap Two Deque Using swap algorithm
        swap(dq4, dq5);  // Swap the contents of dq4 and dq5
        printDq(dq4);
        printDq(dq5);

        // Sort the Deque
        sort(dq.begin(), dq.end());  // ascending
        printDq(dq);
        sort(dq.begin(), dq.end(), greater<int>());  // descending
        printDq(dq);
        // Sort the deque in ascending order using a custom comparator
        sort(dq.begin(), dq.end(), [](int a, int b) { return a < b; });
        printDq(dq);
        // Sort the deque in descending order using a custom comparator
        sort(dq.begin(), dq.end(), [](int a, int b) { return a > b; });
        printDq(dq);

        // Sum of All Elements Deque
        int sum = accumulate(dq.begin(), dq.end(), 0);
        cout << "Sum of all elements in deque: " << sum << endl;

        // Find the maximum element in the deque
        int maxElement = *max_element(dq.begin(), dq.end());
        cout << "Maximum element in deque: " << maxElement << endl;

        // Find the minimum element in the deque
        int minElement = *min_element(dq.begin(), dq.end());
        cout << "Minimum element in deque: " << minElement << endl;

        // Count occurrences of a specific element in the deque
        int c = count_if(dq.begin(), dq.end(), [](int x) { return x == 50; });
        cout << "Count of 50 in deque: " << c << endl;

        // Reverse a Deque
        dq = {111, 222, 333, 444, 555};
        reverse(dq.begin(), dq.end());
        printDq(dq);

        // clear the deque
        dq.clear();
        cout << "Size of the deque after clearing: " << dq.size() << endl;
        cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl;

        // Resizing a deque
        dq.resize(5, 100);  // Resize to 5 elements, fill with 100
        printDq(dq);
        dq.resize(3);  // Resize to 3 elements
        printDq(dq);
        dq.resize(7, 200);  // Resize to 7 elements, fill with 200
        printDq(dq);
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
