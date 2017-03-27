//
//  50_Pow(x,n).cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/22/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <climits>

using namespace std;

// Recursive Method (Double myPow)
class Solution {
public:
    double myPow(double x, int n) { // time: O(logn); space: O(logn)
        if (n == 0) {
            return 1.0;
        }
        double t = myPow(x, n / 2);
        if ((n & 1) == 1) {
            return n < 0 ? (1 / x) * t * t : x * t * t;
        } else {
            return t * t;
        }
    }
};

// // Recursive Method (Double x)
// class Solution {
// public:
//     double myPow(double x, int n) { // time: O(logn); space: O(logn)
//         if (n == 0) {
//             return 1.0;
//         }
//         if (n < 0) {
//             if (n == INT_MIN) {
//                 n++;
//                 n = -n;
//                 x = 1 / x;
//                 return x * x * myPow(x * x, n / 2);
//             }
//             n = -n;
//             x = 1 / x;
//         }
//         return n & 1 == 1 ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
//     }
// };

// Test
int main () {
    Solution solution;
    cout << solution.myPow(8.303, -5) << endl; // 0.00002534106194
    cout << solution.myPow(-1.374, 5) << endl; // -4.897040137
    return 0;
}
