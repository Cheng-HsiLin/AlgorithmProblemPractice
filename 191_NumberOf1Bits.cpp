//
//  191_NumberOf1Bits.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/12/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) { // time: O(1); space: O(1)
        int res = 0;
        while (n) {
            if (n & 1) {
                res++;
            }
            n >>= 1;
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.hammingWeight(11) << endl; // 1011
    cout << solution.hammingWeight(15) << endl; // 1111
    return 0;
}
