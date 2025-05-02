#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

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
void _print(vector<T> v) {
    cout << "[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

/*
A. Manipulative Algorithms
Manipulative algorithms perform operations that modifies the elements of the
given container or rearrange their order. Some of the common manipulative
algorithm includes:

1. copy: Copies a specific number of elements from one range to another.

2. fill: Assigns a specified value to all elements in a range.

3. transform: Applies a function to each element in a range and stores the
result in another range.

4. replace: Replaces all occurrences of a specific value in a range with a new
value.

5. swap: Exchanges the values of two variables.

6. reverse: Reverses the order of elements in a range.

7. rotate: Rotates the elements in a range such that a specific element becomes
the first.

8. remove: Removes all elements with a specified value from a range but does not
reduce the container size. The elements are not actually removed; they are
moved to the end of the range, and the new end of the range is returned.

9. unique: Removes consecutive duplicate elements from a range. The unique
elements are moved to the front of the range, and the new end of the range is
returned. The order of the elements is preserved.

10. partition: Rearranges the elements in a range such that all elements that
are less than a specified value come before all elements that are greater than
or equal to that value.

11. sort: Sorts the elements in a range in ascending order.

12. stable_sort: Sorts the elements in a range in ascending order while
maintaining the relative order of equal elements.

13. nth_element: Partially sorts the elements in a range such that the element
at the nth position is the same as it would be in a fully sorted range.

14. next_permutation: Generates the next lexicographical permutation of a range.

15. prev_permutation: Generates the previous lexicographical permutation of a
range.



B. Non-Manipulative Algorithms
Non-manipulating algorithms are the type of algorithms provided by the Standard
Template Library (STL) that operate on elements in a range without altering
their values or the order of the elements. The below are the few examples of the
STL’s non-manipulative algorithms:

1. max_element: Find the maximum element in the given range.

2. min_element : To find the minimum element in the given range.

3. accumulate: Finds the sum of the elements of the given range.

4. count: Counts the occurrences of given element in the range.

5. find: Returns an iterator to the first occurrence of an element in the range.

6. is_permutation: Checks if one range is a permutation of another.

7. is_sorted: Checks if the elements in a range are sorted in non-decreasing
order.

8. partial_sum: Computes the cumulative sum of elements in a range.

9. adjacent_difference: Computes the difference between adjacent elements in a
range.

10. search: Searches for a subsequence in a range.

11. search_n: Searches for a subsequence of n consecutive elements in a range.

12. find_if: Returns an iterator to the first element in a range that satisfies
a given predicate.

13. find_if_not: Returns an iterator to the first element in a range that does
not satisfy a given predicate.

14. equal: Checks if two ranges are equal.

15. lexicographical_compare: Compares two ranges lexicographically.

16. includes: Checks if one range is a subset of another.
*/

class STLAlgo {
   public:
    void manipulativeAlgorithms() {
        cout << "Manipulative Algorithms" << endl;
        vector<int> v = {1, 2, 3, 4, 5};
        debug(v);
        vector<int> v2(5);
        debug(v2);

        copy(v.begin(), v.end(), v2.begin());  // 1. copy
        cout << "Copy: ";
        debug(v2);

        fill(v2.begin(), v2.end(), 0);  // 2. fill
        cout << "Fill: ";
        debug(v2);

        transform(v.begin(), v.end(), v2.begin(),
                  [](int x) { return x * 2; });  // 3. transform
        cout << "Transform: ";
        debug(v2);

        replace(v.begin(), v.end(), 3, 0);  // 4. replace
        cout << "Replace: ";
        debug(v);

        swap(v[0], v[1]);  // 5. swap
        cout << "Swap: ";
        debug(v);

        reverse(v.begin(), v.end());  // 6. reverse
        cout << "Reverse: ";
        debug(v);

        rotate(v.begin(), v.begin() + 2, v.end());  // 7. rotate
        cout << "Rotate: ";
        debug(v);

        remove(v.begin(), v.end(), 0);  // 8. remove
        cout << "Remove: ";
        debug(v);

        unique(v.begin(), v.end());  // 9. unique
        cout << "Unique: ";
        debug(v);
        v.erase(unique(v.begin(), v.end()), v.end());  // Remove duplicates
        cout << "After Erase: ";
        debug(v);

        v.push_back(6);
        v.push_back(3);
        v.push_back(1);
        v.push_back(2);
        v.push_back(4);
        cout << "Before Partition: ";
        debug(v);
        partition(v.begin(), v.end(),
                  [](int x) { return x < 3; });  // 10. partition
        cout << "Partition: ";
        debug(v);
        // Note: The partition algorithm does not guarantee the order of
        // elements within the partitions. It only ensures that all elements
        // satisfying the predicate are moved to the front of the range.

        sort(v.begin(), v.end());  // 11. sort
        cout << "Sort: ";
        debug(v);

        sort(v.begin(), v.end(), [](int a, int b) { return a + b > 7; });
        cout << "Before Stable Sort: ";
        debug(v);
        stable_sort(v.begin(), v.begin() + 6);  // 12. stable_sort
        cout << "Stable Sort: ";
        debug(v);

        vector<int> v3 = {3, 2, 10, 45, 33, 56, 23, 47};
        vector<int> v4(v3);
        cout << "Before Nth Element: ";
        debug(v3);
        nth_element(v3.begin(), v3.begin() + 4, v3.end());  // 13. nth_element
        cout << "After Nth Element (N=5): ";
        debug(v3);
        // Here n = 5 because of v3.begin() + 4
        // Hence output : [ 3 2 10 23 33 56 45 47 ]
        // Because Here, the 5th element is 33, and all elements to its left are
        // smaller than it and all elements to its right are greater than it.
        cout << "Before Nth Element: ";
        debug(v4);  // v4 = [3, 2, 10, 45, 33, 56, 23, 47]
        nth_element(v4.begin(), v4.begin() + 5, v4.end());
        cout << "After Nth Element (N=6): ";
        debug(v4);  // v4
        // Here n = 6 because of v4.begin() + 5
        // Hence output : [ 3 2 10 23 33 45 56 47 ]
        // Because Here, the 6th element is 45, and all elements to its left are
        // smaller than it and all elements to its right are greater than it.

        vector<int> v5 = {1, 2, 3};
        cout << "Next Permutation: \n";  // 14. next_permutation
        do {
            debug(v5);
        } while (next_permutation(v5.begin(), v5.end()));

        // v5 = {1, 2, 3};
        v5 = {3, 2, 1};
        cout << "Prev Permutation: \n";  // 15. prev_permutation
        do {
            debug(v5);
        } while (prev_permutation(v5.begin(), v5.end()));
    }

    void nonManipulativeAlgorithms() {
        cout << "Non-Manipulative Algorithms" << endl;
        vector<int> v = {1, 2, 3, 4, 5};

        cout << "Max Element: " << *max_element(v.begin(), v.end())
             << endl;  // 1. max_element
        cout << "Min Element: " << *min_element(v.begin(), v.end())
             << endl;  // 2. min_element
        cout << "Sum: " << accumulate(v.begin(), v.end(), 0)
             << endl;  // 3. accumulate
        cout << "Count: " << count(v.begin(), v.end(), 3) << endl;  // 4. count
        cout << "Find: " << *find(v.begin(), v.end(), 3) << endl;   // 5. find
        cout << "Is Permutation: "
             << is_permutation(v.begin(), v.end(), v.begin())
             << endl;  // 6. is_permutation
        cout << "Is Sorted: " << is_sorted(v.begin(), v.end())
             << endl;  // 7. is_sorted

        cout << "Partial Sum: ";
        vector<int> ps(v.size());
        partial_sum(v.begin(), v.end(), ps.begin());  // 8. partial_sum
        debug(ps);

        cout << "Adjacent Difference: ";
        vector<int> ad(v.size());
        adjacent_difference(v.begin(), v.end(),
                            ad.begin());  // 9. adjacent_difference
        debug(ad);

        cout << "Search: " << *search(v.begin(), v.end(), v.begin(), v.end())
             << endl;  // 10. search
        cout << "Search N: " << *search_n(v.begin(), v.end(), 3, 3)
             << endl;  // 11. search_n
        cout << "Find If: " << *find_if(v.begin(), v.end(), [](int x) {
            return x > 3;
        }) << endl;  // 12. find_if
        cout << "Find If Not: " << *find_if_not(v.begin(), v.end(), [](int x) {
            return x > 3;
        }) << endl;  // 13. find_if_not
        cout << "Equal: " << equal(v.begin(), v.end(), v.begin())
             << endl;  // 14. equal
        cout << "Lexicographical Compare: "
             << lexicographical_compare(v.begin(), v.end(), v.begin(), v.end())
             << endl;  // 15. lexicographical_compare
        cout << "Includes: " << includes(v.begin(), v.end(), v.begin(), v.end())
             << endl;  // 16. includes
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
    STLAlgo sol;
    int T = 1;
    // cin >> T;
    while (T--) {
        sol.manipulativeAlgorithms();
        cout << endl;
        sol.nonManipulativeAlgorithms();
    }
    cerr << "Time taken: " << (float)clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
