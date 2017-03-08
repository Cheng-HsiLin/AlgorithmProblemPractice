//
//  7_ReverseInteger.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) { // time: O(logx); space: O(1)
        long num = 0;
        while (x != 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        // return 0 if overflow occurs
        return (num < INT_MIN || num > INT_MAX) ? 0 : (int)num;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.reverse(123) << endl;
    cout << solution.reverse(-123) << endl;
    cout << solution.reverse(1000000003) << endl;
    cout << solution.reverse(-1000000003) << endl;
    return 0;
}
