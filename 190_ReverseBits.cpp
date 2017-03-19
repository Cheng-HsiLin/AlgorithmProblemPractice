//
//  190_ReverseBits.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/18/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) { // time: O(1); space: O(1)
//         uint32_t res = 0;
//         for (int i = 0; i < 32; i++) {
//             res <<= 1;
//             res |= (n & 1);
//             n >>= 1;
//         }
//         return res;
//     }
// };

// Follow-Up: If this function is called many times, how would you optimize it?
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.reverseBits(43261596) << endl; // 964176192
    return 0;
}
