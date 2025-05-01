#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

/*
In C++, queue container follows the FIFO (First In First Out) order of insertion
and deletion. According to it, the elements that are inserted first should be
removed first. This is possible by inserting elements at one end (called back)
and deleting them from the other end (called front) of the data structure.
*/

class Solution {
   private:
#define printQueue(x)   \
    cout << #x << ": "; \
    _print(x);          \
    cout << endl;
    void _print(int t) { cout << t; }
    template <class T>
    void _print(queue<T> q) {
        cout << "[ ";
        while (!q.empty()) {
            _print(q.front());
            cout << " ";
            q.pop();
        }
        cout << "]";
    }

   public:
    void solve() {
        // Initializing a queue - FIFO
        queue<int> q;

        // Inserting elements
        q.push(1);  // or emplace( )
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        printQueue(q);

        // Deleting elements
        q.pop();
        printQueue(q);

        // Accessing elements
        cout << "Front element: " << q.front() << endl;
        cout << "Back element: " << q.back() << endl;

        // Size of the queue
        cout << "Size of the queue: " << q.size() << endl;

        // Create another queue from queue
        queue<int> q2(q);
        printQueue(q2);

        // Check if queue is empty
        cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

        // Reverse the queue
        queue<int> q3;
        while (!q2.empty()) {
            q3.push(q2.front());
            q2.pop();
        }
        printQueue(q3);

        // Swap two queues
        queue<int> q4;
        q4.push(10);
        q4.push(20);
        q4.push(30);
        q4.push(40);
        printQueue(q4);

        cout << "After swap:" << endl;
        q3.swap(q4);
        printQueue(q3);
        printQueue(q4);

        // Clear the queue
        while (!q3.empty()) {
            q3.pop();
        }
        printQueue(q3);
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
