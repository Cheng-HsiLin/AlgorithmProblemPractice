//
//  69_Sqrt(x).cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/21/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

// Binary Search Method
class Solution {
public:
    int mySqrt(int x) { // time: O(logn); space: O(1)
        if (x <= 1) {
            return x;
        }
        int low = 1, high = x;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // intentionally compare mid and x / mid instead of mid * mid and x in order to avoid overflow
            if (mid <= x / mid) { // even equal condition add 1
                low = mid + 1;
            } else { // mid > x / mid
                high = mid - 1;
            }
        }
        return low - 1;
    }
};

// class Solution {
// public:
//     int mySqrt(int x) { // time: O(logn); space: O(1)
//         if (x <= 1) {
//             return x;
//         }
//         int left = 1, right = x;
//         while (true) {
//             int mid = left + (right - left) / 2;
//             if (mid > x / mid) {
//                 right = mid - 1;
//             } else { // mid <= x / mid
//                 if (mid + 1 > x / (mid + 1)) {
//                     return mid;
//                 }
//                 left = mid + 1;
//             }
//         }
//     }
// };

// // Newton Method
// class Solution {
// public:
//     int mySqrt(int x) { // time: O(log(n)^3); space: O(1)
//         if (x <= 1) {
//             return x;
//         }
//         int r = x / 2;
//         while (r > x /r) {
//             r = (r + x / r) / 2;
//         }
//         return r;
//     }
// };

// Test
int main () {
    Solution solution;
    cout << solution.mySqrt(10) << endl;
    cout << solution.mySqrt(15) << endl;
    cout << solution.mySqrt(99) << endl;
    return 0;
}
