//
//  29_DivideTwoIntegers.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/27/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

// // Math Method
// class Solution {
// public:
//     int divide(int dividend, int divisor) { // time: O(logn?); space: O(logn?)
//         // a / b = e ^ ln(a) / e ^ ln(b) = e ^ (ln(a) - ln(b))
//         if (dividend == 0) {
//             return 0;
//         }
//         if (divisor == 0) {
//             return INT_MAX;
//         }
//         // natural logarithm
//         double ln_a = log(fabs(dividend));
//         double ln_b = log(fabs(divisor));
//         // exponential function
//         long long res = exp(ln_a - ln_b);
//         if ((dividend < 0) ^ (divisor < 0) == true) {
//             res = -res;
//         }
//         if (res > INT_MAX) {
//             return INT_MAX;
//         }
//         return res;
//     }
// };

// Bit Manipulation
class Solution {
public:
    int divide(int dividend, int divisor) { // time: O(log(the answer of division)); space: O(1)
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        int sign = ((dividend < 0) ^ (divisor < 0)) == true ? -1 : 1;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) {
            long tmp = dvs, count = 1;
            while (dvd >= (tmp << 1)) {
                tmp <<= 1;
                count <<= 1;
            }
            dvd -= tmp;
            res += count;
        }
        return sign == 1 ? res : -res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.divide(INT_MIN, -1) << endl;
    cout << solution.divide(14, 3) << endl;
    return 0;
}
