//
//  326_PowerOfThree.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/13/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

// // Iterative Loop Method
// class Solution {
// public:
//     bool isPowerOfThree(int n) { // time: O(logn); space: O(1)
//         if (n <= 0) {
//             return false;
//         }
//         while (n % 3 == 0) {
//             n /= 3;
//         }
//         return n == 1;
//     }
// };

// Follow-Up: Without Using any Loop / Recursion
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        return pow(3, (int)(log10(n) / log10(3))) == n;
    }
};

// // Math Solution from https://leetcode.com/articles/power-of-three/
// class Solution {
// public:
//     bool isPowerOfThree(int n) { // time: O(1); space: O(1)
//         return n > 0 && 1162261467 % n == 0;
//     }
// };

// Test
int main () {
    Solution solution;
    cout << (solution.isPowerOfThree(729) ? "True" : "False") << endl;
    cout << (solution.isPowerOfThree(531441) ? "True" : "False") << endl;
    return 0;
}
