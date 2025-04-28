#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

/*
In C++, stack container follows LIFO (Last In First Out) order of insertion and
deletion. It means that most recently inserted element is removed first and the
first inserted element will be removed last. This is done by inserting and
deleting elements at only one end of the stack which is generally called the top
of the stack.
*/

class Solution {
   private:
#define printStack(x)   \
    cout << #x << ": "; \
    _print(x);          \
    cout << endl;
    void _print(int t) { cout << t; }
    template <class T>
    void _print(stack<T> st) {
        cout << "[ ";
        while (!st.empty()) {
            _print(st.top());
            cout << " ";
            st.pop();
        }
        cout << "]";
    }

   public:
    void solve() {
        // Initializing a stack - LIFO
        stack<int> st;

        // Inserting elements
        st.push(1);  // or emplace( )
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        printStack(st);

        // Deleting elements
        st.pop();
        printStack(st);

        // Accessing the top element
        cout << "Top element: " << st.top() << endl;

        // Size of the stack
        cout << "Size of the stack: " << st.size() << endl;

        // Create another stack from stack
        stack<int> st2(st);
        printStack(st2);

        // Check if stack is empty
        cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

        // Reverse the stack
        stack<int> st3;
        while (!st2.empty()) {
            st3.push(st2.top());
            st2.pop();
        }
        printStack(st3);

        // Swap two stacks
        stack<int> st4;
        st4.push(10);
        st4.push(20);
        st4.push(30);
        st4.push(40);
        printStack(st4);

        swap(st3, st4);
        cout << "After swapping:" << endl;
        printStack(st3);
        printStack(st4);

        // Clear the stack
        while (!st3.empty()) {
            st3.pop();
        }
        printStack(st3);
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
