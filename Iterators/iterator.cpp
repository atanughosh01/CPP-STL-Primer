#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/*
Iterators are the pointer like objects that are used to point to the memory
addresses of STL containers. They are one of the most important components that
contributes the most in connecting the STL algorithms with the containers.
Iterators are defined inside the <iterator> header file.

In C++ STL, iterators are of 5 types:
    1. Input Iterators
    2. Output Iterators
    3. Forward Iterators
    4. Bidirectional Iterators
    5. Random Access Iterators
*/

// Input Iterators can be used to read values from a sequence once and only move
// forward. Definition of std::find() template
template <class InputIterator, class T>
InputIterator custom_find(InputIterator first, InputIterator last,
                          const T& val) {
    while (first != last) {
        if (*first == val) return first;
        ++first;
    }
    return last;
}

// Output Iterators can be used to write values into a sequence once and only
// move forward. Definition of std::move()
template <class InputIterator, class OutputIterator>
OutputIterator custom_move(InputIterator first, InputIterator last,
                           OutputIterator result) {
    while (first != last) {
        *result = std::move(*first);
        ++result;
        ++first;
    }
    return result;
}

// Definition of std::copy() template
template <class InputIterator, class OutputIterator>
OutputIterator custom_copy(InputIterator first, InputIterator last,
                           OutputIterator result) {
    while (first != last) {
        *result++ = *first++;
    }
    return result;
}

// Forward Iterators combine the features of both input and output iterators.
// They can be used to read and write values from a sequence and can only move
// forward. Definition of std::replace()
template <class ForwardIterator, class T>
void custom_replace(ForwardIterator first, ForwardIterator last,
                    const T& old_value, const T& new_value) {
    while (first != last) {
        if (*first == old_value) {  // L1
            *first = new_value;     // L2
        }
        ++first;
    }
}

// Bidirectional Iterators support all operations of forward iterators and
// additionally can move backward. Definition of std::reverse_copy()
template <class BidirectionalIterator, class OutputIterator>
OutputIterator custom_reverse_copy(BidirectionalIterator first,
                                   BidirectionalIterator last,
                                   OutputIterator result) {
    while (first != last) {
        *result++ = *--last;
    }
    return result;
}

// Random Access Iterators: Random Access Iterators support all operations of
// bidirectional iterators and additionally provide efficient random access to
// elements. Definition of std::random_shuffle()
template <class RandomAccessIterator, class RandomNumberGenerator>
void custom_random_shuffle(RandomAccessIterator first,
                           RandomAccessIterator last,
                           RandomNumberGenerator& gen) {
    typedef typename iterator_traits<RandomAccessIterator>::difference_type
        difference_type;
    difference_type i, n;
    n = (last - first);
    for (i = n - 1; i > 0; --i) {
        // Generate a random index in the range [0, i]
        difference_type j = gen() % (i + 1);
        // Swap the elements at indices i and j
        std::swap(first[i], first[j]);
        // Alternatively, you can use the following line to swap elements:
        // std::iter_swap(first + i, first + gen(i + 1)); // C++11 and later
        // Note: The above line is equivalent to the following line in C++11:
        // std::iter_swap(first + i, first + first[gen(i + 1)]);
    }
}

class Solution {
   public:
    void solve() {
        // Example usage of iterators
        vector<int> vec = {1, 2, 3, 4, 5};
        cout << "Original vector: ";
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

        // Using std::custom_find() to find an element in the vector
        auto it = custom_find(vec.begin(), vec.end(), 3);
        if (it != vec.end()) {
            cout << "Element found: " << *it << endl;
        } else {
            cout << "Element not found" << endl;
        }

        // Using std::custom_copy() to copy elements from one vector to another
        vector<int> vec2(5);
        custom_copy(vec.begin(), vec.end(), vec2.begin());
        cout << "Copied vector: ";
        for (auto it2 = vec2.begin(); it2 != vec2.end(); ++it2) {
            cout << *it2 << " ";
        }
        cout << endl;

        // Using std::custom_move() to move elements from one vector to another
        vector<int> vec3(5);
        custom_move(vec.begin(), vec.end(), vec3.begin());
        cout << "Moved vector: ";
        for (auto it3 = vec3.begin(); it3 != vec3.end(); ++it3) {
            cout << *it3 << " ";
        }
        cout << endl;

        // Using std::custom_replace() to replace elements in the vector
        custom_replace(vec.begin(), vec.end(), 3, 10);
        cout << "Replaced vector: ";
        for (auto it4 = vec.begin(); it4 != vec.end(); ++it4) {
            cout << *it4 << " ";
        }
        cout << endl;

        // Using std::custom_reverse_copy() to reverse copy elements from one
        // vector to another
        vector<int> vec4(5);
        custom_reverse_copy(vec.begin(), vec.end(), vec4.begin());
        cout << "Reversed copied vector: ";
        for (auto it5 = vec4.begin(); it5 != vec4.end(); ++it5) {
            cout << *it5 << " ";
        }
        cout << endl;

        // Using std::custom_random_shuffle() to shuffle elements in the vector
        random_device rd;
        mt19937 gen(rd());  // Random number generator
        custom_random_shuffle(vec.begin(), vec.end(), gen);
        cout << "Shuffled vector: ";
        for (auto it6 = vec.begin(); it6 != vec.end(); ++it6) {
            cout << *it6 << " ";
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
