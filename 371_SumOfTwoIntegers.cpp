//
//  371_SumOfTwoIntegers.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/11/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

// Bit Manipulation Method
class Solution {
public:
    int getSum(int a, int b) { // time: (logn); space: O(1)
        if (a == 0) {
            return b;
        } else if (b == 0) {
            return a;
        }
        int carry = 0;
        while (b != 0) {
            carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.getSum(1, 3) << endl;
    cout << solution.getSum(2, 4) << endl;
    return 0;
}
