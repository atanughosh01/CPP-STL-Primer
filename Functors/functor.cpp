#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/*
Consider a function that takes only one argument. However, while calling this
function we have a lot more information that we would like to pass to this
function, but we cannot as it accepts only one parameter. What can be done?

One obvious answer might be global variables. However, good coding practices do
not advocate the use of global variables and say they must be used only when
there is no other alternative.

Functors are objects that can be treated as though they are a function or
function pointer. Functors are most commonly used along with STLs in a scenario
like following:
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
void _print(vector<T>& v) {
    cout << "[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

// Functor example - 1
struct Adder {
    int operator()(int a, int b) {
        // Adds two integers
        return a + b;
    }
};

// Functor example - 2
struct CustomSort {
    bool operator()(int a, int b) const {
        // Custom comparator: sorts in ascending order of squares
        return (a * a) < (b * b);
    }
};

// Functor example - 3
struct CustomIncrement {
    int operator()(int a) const {
        // Custom increment: adds 10 to the input
        return a + 10;
    }
};

// Functor example - 4
class VariableIncrement {
   private:
    int incrementValue;

   public:
    VariableIncrement(int inc) : incrementValue(inc) {}

    int operator()(int arrNum) const {
        // Custom increment: adds incrementValue to the input
        return arrNum + incrementValue;
    }
};

class Solution {
   public:
    void solve() {
        // Functor example - 1
        Adder add;
        int res = add(111, 222);
        cout << "111 + 222 = " << res << endl;

        // Functor example - 2
        vector<int> v = {4, 2, -5, 3, 111, -15, 34, 0, 2, 871, 1, -210, 3};
        cout << "\nBefore sorting: ";
        debug(v);
        sort(v.begin(), v.end(), CustomSort());
        cout << "After sorting: ";
        debug(v);

        // Functor example - 3
        int arr1[] = {1, 2, 3, 4, 5};
        int n = sizeof(arr1) / sizeof(arr1[0]);
        cout << "\nBefore incrementing: arr1 = [";
        for (auto& e : arr1) cout << e << " ";
        cout << "]\nAfter incrementing: arr1 = [";
        transform(arr1, arr1 + n, arr1, CustomIncrement());
        for (auto& e : arr1) cout << e << " ";
        cout << "]\n";

        // Functor example - 4
        int arr2[] = {11, -2, 331, 40, 5};
        int n2 = sizeof(arr2) / sizeof(arr2[0]);
        int increaseEachBy = 100;
        cout << "\nBefore incrementing: arr2 = [";
        for (auto& e : arr2) cout << e << " ";
        cout << "]\nAfter incrementing: arr2 = [";
        transform(arr2, arr2 + n2, arr2, VariableIncrement(increaseEachBy));
        for (auto& e : arr2) cout << e << " ";
        cout << "]\n";

        /*
            Functors can be classified into multiple types based on the
            type of operator they perform:

            1. Arithmetic Functors
            2. Relational Functors
            3. Logical Functors
            4. Bitwise Functors
        */

        // 1. Arithmetic Functors
        // plus – Returns the sum of two parameters.
        auto plus = [](int a, int b) { return a + b; };
        cout << "\nplus(10, 20) = " << plus(10, 20) << endl;

        // minus – Returns the difference of two parameters.
        auto minus = [](int a, int b) { return a - b; };
        cout << "minus(20, 10) = " << minus(20, 10) << endl;

        // multiplies – Returns the product of two parameters.
        auto multiplies = [](int a, int b) { return a * b; };
        cout << "multiplies(10, 20) = " << multiplies(10, 20) << endl;

        // divides – Returns the result after dividing two parameters.
        auto divides = [](int a, int b) { return a / b; };
        cout << "divides(20, 10) = " << divides(20, 10) << endl;

        // modulus – Returns the remainder after dividing two parameters.
        auto modulus = [](int a, int b) { return a % b; };
        cout << "modulus(20, 10) = " << modulus(20, 10) << endl;

        // negate – Returns the negated value of a parameter.
        auto negate = [](int a) { return -a; };
        cout << "negate(10) = " << negate(10) << endl;
        cout << "negate(-10) = " << negate(-10) << endl;

        // 2. Relational Functors
        // equal_to – Returns true if the two parameters are equal.
        auto equal_to = [](int a, int b) { return a == b; };
        cout << "\nequal_to(10, 20) = " << equal_to(10, 20) << endl;
        cout << "equal_to(10, 10) = " << equal_to(10, 10) << endl;

        // not_equal_to – Returns true if the two parameters are not equal.
        auto not_equal_to = [](int a, int b) { return a != b; };
        cout << "not_equal_to(10, 20) = " << not_equal_to(10, 20) << endl;
        cout << "not_equal_to(10, 10) = " << not_equal_to(10, 10) << endl;

        // greater – Returns true if the parameter is greater than second.
        auto greater = [](int a, int b) { return a > b; };
        cout << "greater(20, 10) = " << greater(20, 10) << endl;
        cout << "greater(10, 20) = " << greater(10, 20) << endl;
        cout << "greater(10, 10) = " << greater(10, 10) << endl;

        // greater_equal – Returns true if first parameter is
        // greater than or equal to second.
        auto greater_equal = [](int a, int b) { return a >= b; };
        cout << "greater_equal(20, 10) = " << greater_equal(20, 10) << endl;
        cout << "greater_equal(10, 20) = " << greater_equal(10, 20) << endl;

        // less – Returns true if first parameter is less than second.
        auto less = [](int a, int b) { return a < b; };
        cout << "less(10, 20) = " << less(10, 20) << endl;
        cout << "less(20, 10) = " << less(20, 10) << endl;
        cout << "less(10, 10) = " << less(10, 10) << endl;

        // less_equal – Returns true if first parameter is less than or equal to
        // second.
        auto less_equal = [](int a, int b) { return a <= b; };
        cout << "less_equal(10, 20) = " << less_equal(10, 20) << endl;
        cout << "less_equal(20, 10) = " << less_equal(20, 10) << endl;

        // 3. Logical Functors
        // logical_and – Returns the result of Logical AND operation of two
        // parameters.
        auto logical_and = [](bool a, bool b) { return a && b; };
        cout << "\nlogical_and(true, false) = " << logical_and(true, false)
             << endl;
        cout << "logical_and(true, true) = " << logical_and(true, true) << endl;
        cout << "logical_and(false, false) = " << logical_and(false, false)
             << endl;

        // logical_or – Returns the result of Logical OR operation
        // of two parameters.
        auto logical_or = [](bool a, bool b) { return a || b; };
        cout << "logical_or(true, false) = " << logical_or(true, false) << endl;
        cout << "logical_or(true, true) = " << logical_or(true, true) << endl;
        cout << "logical_or(false, false) = " << logical_or(false, false)
             << endl;

        // logical_not – Returns the result of Logical NOT
        //  operation of the parameters.
        auto logical_not = [](bool a) { return !a; };
        cout << "logical_not(true) = " << logical_not(true) << endl;
        cout << "logical_not(false) = " << logical_not(false) << endl;

        // 4. Bitwise Functors
        // bit_and – Returns the result of Bitwise AND operation of two
        // parameters.
        auto bit_and = [](int a, int b) { return a & b; };
        cout << "\nbit_and(10, 20) = " << bit_and(10, 20) << endl;
        cout << "bit_and(10, 10) = " << bit_and(10, 10) << endl;

        // bit_or – Returns the result of Bitwise OR operation of
        // two parameters.
        auto bit_or = [](int a, int b) { return a | b; };
        cout << "bit_or(10, 20) = " << bit_or(10, 20) << endl;

        // bit_xor – Returns the result of Bitwise XOR operation
        // of two parameters.
        auto bit_xor = [](int a, int b) { return a ^ b; };
        cout << "bit_xor(10, 20) = " << bit_xor(10, 20) << endl;
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
