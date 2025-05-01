#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/*
The Utility Library is a collection of utility components provided by the
Standard Template Library (STL) that does not fall in the above categories. It
offers various features such as pairs, tuples, etc.

The memory library contains the function that helps users to efficiently manage
the memory such as std::move, smart pointers, etc.

1. Pair: Container to store and manipulate heterogeneous data.

2. Move Semantics: It allows the transfer of resources from one object to
another without copying.

3. Smart Pointers: They are a wrapper over the raw pointers and helps in
avoiding errors associated with pointers.

4. Utility Functions: Utility functions in C++ provide important operations like
std::forward to facilitate efficient, generic and safe code manipulation.

5. Integer Sequence: Enable compile-time generation of integer sequences, useful
in metaprogramming.
*/

template <typename T, T... Is>
void print_sequence(integer_sequence<T, Is...>) {
    cout << "The sequence is: ";
    ((cout << Is << ' '), ...);  // fold expression to print sequence
    cout << endl;
}

// Struct to calculate the size of an integer_sequence
template <typename T, T... Ints>
struct integer_sequence_size;

// Partial specialization for an integer_sequence with at
// least one element
template <typename T, T Head, T... Tail>
struct integer_sequence_size<T, Head, Tail...> {
    static constexpr size_t value =
        1 + integer_sequence_size<T, Tail...>::value;
};

// Specialization for an empty integer_sequence
template <typename T>
struct integer_sequence_size<T> {
    static constexpr size_t value = 0;
};

class Rectangle {
   private:
    int length;
    int breadth;

   public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        int area = length * breadth;
        return area;
    }
};

class Solution {
   public:
    void solve() {
        // Pair example
        pair<int, string> p0(1, "Hello");
        cout << "Pair: (" << p0.first << ", " << p0.second << ")\n";
        pair<int, int> p1 = {3, 5};
        pair<int, int> p2 = {3, 7};
        pair<int, int> p3 = {2, 5};

        // printing result of comparision
        cout << boolalpha;
        cout << "p1 == p2: " << (p1 == p2) << endl;
        cout << "p1 != p3: " << (p1 != p3) << endl;
        cout << "p1 > p3: " << (p1 > p3) << endl;
        cout << "p1 < p2: " << (p1 < p2) << endl;
        cout << "p1 >= p3: " << (p1 >= p3) << endl;
        cout << "p3 <= p1: " << (p3 <= p1) << endl;

        // Move semantics example
        string str = "Hello, World!";
        string moved_str = move(str);  // str is now empty
        cout << "Is str empty? " << boolalpha << str.empty() << endl;
        cout << "Moved string: " << moved_str << endl;

        // Smart pointer example
        /*
            Types of Smart Pointers
            C++ libraries provide implementations of smart pointers in the
           following types:

            auto_ptr : Deprecated in C++11, use std::unique_ptr instead.

            unique_ptr : Represents exclusive ownership of an object. It cannot
           be copied, only moved. It automatically deletes the object when it
           goes out of scope.

            shared_ptr : Represents shared ownership of an object. Multiple
           shared_ptr instances can own the same object. It keeps track of the
           number of references to the object and deletes it when the last
           reference is released.

            weak_ptr : Represents a non-owning reference to an object managed by
           shared_ptr. It does not affect the reference count of the object. It
           is used to break circular references between shared_ptr instances.
        */
        unique_ptr<Rectangle> P1(new Rectangle(10, 5));
        cout << "P1->area() : " << P1->area() << endl;
        unique_ptr<Rectangle> P2;
        // Copy the addres of P1 into p2
        P2 = move(P1);
        cout << "P2->area() : " << P2->area() << endl;

        shared_ptr<Rectangle> P3(new Rectangle(10, 5));
        cout << "P3->area() : " << P3->area() << endl;
        shared_ptr<Rectangle> P4;
        // P3 and P4 are pointing to same object
        P4 = P3;
        cout << "P4->area() : " << P4->area() << endl;
        cout << "P3->area() : " << P3->area() << endl;
        cout << "P3.use_count() : " << P3.use_count() << endl;

        // Create shared_ptr Smart Pointer
        shared_ptr<Rectangle> P5(new Rectangle(10, 5));
        // Created a weak_ptr smart pointer
        weak_ptr<Rectangle> P6(P5);
        cout << "P5->area() : " << P5->area() << endl;
        // Returns the number of shared_ptr objects that manage the object
        cout << "P6.use_count() : " << P6.use_count() << endl;

        // Utility function example
        auto func = [](int x) { return x * x; };
        cout << "Utility function result: " << func(5) << endl;

        // Integer sequence example
        print_sequence(integer_sequence<int, 10, 2, 333, 40>{});
        cout << "Size : "
             << integer_sequence_size<int, 0, 10, 2, 333, 40>::value << endl;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("zin.txt", "r", stdin);
    freopen("zout.txt", "w", stdout);
    freopen("zerr.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution sol;
    int T = 1;
    // cin >> T;
    while (T--) {
        sol.solve();
    }
    cerr << "Time taken: " << (float)clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
