//
//  172_FactorialTrailingZeroes.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/13/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) { // time: O(logn); space: O(1)
        int res = 0;
        for (long i = 5; (n / i) > 0; i *= 5) {
            res += (n / i);
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.trailingZeroes(10) << endl;
    cout << solution.trailingZeroes(15) << endl;
    return 0;
}
