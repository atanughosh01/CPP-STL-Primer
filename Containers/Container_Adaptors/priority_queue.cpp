#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

/*
In C++, priority queue is a type of queue (container adaptor) in which there is
some priority assigned to the elements. It provides a way to manage a
collection of elements in a way that allows for efficient retrieval of the
highest (or lowest) priority element. By default, the value of the element being
inserted is considered as priority (implemented as max heap). Higher its value,
higher its priority. But this can be changed to any desired priority scheme as
per requirement.
*/

class Solution {
   private:
#define printPQ(x)      \
    cout << #x << ": "; \
    _print(x);          \
    cout << endl;
    void _print(int t) { cout << t; }
    template <class T>
    void _print(priority_queue<T> pq) {
        cout << "[ ";
        while (!pq.empty()) {
            _print(pq.top());
            cout << " ";
            pq.pop();
        }
        cout << "]";
    }
    template <class T>
    void _print(priority_queue<T, vector<T>, greater<T>> pq) {
        cout << "[ ";
        while (!pq.empty()) {
            _print(pq.top());
            cout << " ";
            pq.pop();
        }
        cout << "]";
    }

   public:
    void solve() {
        // Initializing a priority queue
        priority_queue<int> pq1;  // max heap: highest val at top
        priority_queue<int, vector<int>, greater<int>>
            pq2;  // min heap: lowest val at top

        // Inserting elements - O(log n) time
        pq1.push(1);  // or emplace( )
        pq1.push(-4);
        pq1.push(21);
        pq1.push(5);
        pq1.push(30);
        pq1.push(500);
        printPQ(pq1);

        pq2.push(1);  // or emplace( )
        pq2.push(-4);
        pq2.push(21);
        pq2.push(5);
        pq2.push(30);
        pq2.push(500);
        printPQ(pq2);

        // Deleting elements - O(log n) time
        pq1.pop();
        printPQ(pq1);

        // Accessing the top element
        cout << "Top element: " << pq1.top() << endl;
        cout << "Top element: " << pq2.top() << endl;

        // Size of the priority queue
        cout << "Size of PQ1: " << pq1.size() << endl;
        cout << "Size of PQ2: " << pq2.size() << endl;

        // Create another priority queue from priority queue
        priority_queue<int> pq3(pq1);
        printPQ(pq3);

        // Check if priority queue is empty
        cout << "Is PQ1 empty? " << (pq1.empty() ? "Yes" : "No") << endl;

        // Creating priority queue from other container
        vector<int> v = {9, 8, 6, 10, 4, 2};
        priority_queue<int> pq4(v.begin(), v.end());
        printPQ(pq4);

        // Swapping two priority queues
        cout << "Before swapping:" << endl;
        printPQ(pq1);
        printPQ(pq4);
        pq1.swap(pq4);
        cout << "After swapping:" << endl;
        printPQ(pq1);
        printPQ(pq4);

        // Priority queue with custom comparator
        // first part in ascending and second part in descending first basis
        class Compare {
           public:
            bool operator()(pii a, pii b) {
                if (a.first > b.first) {
                    return true;
                } else if (a.first == b.first && a.second < b.second) {
                    return true;
                }
                return false;
            }
        };

        priority_queue<pii, vector<pii>, Compare> ds;
        ds.push({100, 11});
        ds.push({100, 41});
        ds.push({100, 21});
        ds.push({300, 1});
        ds.push({300, 2});
        ds.push({1, 1});
        ds.push({1, 2});
        ds.push({1, 20});

        cout << "The PQ looks like:" << endl;
        while (!ds.empty()) {
            cout << ds.top().first << " " << ds.top().second << endl;
            ds.pop();  // heapify after removing the top element
        }
        cout << endl;
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
