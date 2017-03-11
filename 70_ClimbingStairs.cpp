//
//  70_ClimbingStairs.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// // DP Method with 1D array
// class Solution {
// public:
//     int climbStairs(int n) { // time: O(n); space: O(n)
//         vector<int> dp(n + 1, 0);
//         dp[0] = 1, dp[1] = 1;
//         for (int i = 2; i <= n; i++) {
//             dp[i] = dp[i - 2] + dp[i - 1];
//         }
//         return dp[n];
//     }
// };

// DP Method with Two Variables
class Solution {
public:
    int climbStairs(int n) { // time: O(n); space: O(1)
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int twoStep = 1, oneStep = 2, res = 0;
        for (int i = 3; i <= n; i++) {
            res = twoStep + oneStep;
            twoStep = oneStep;
            oneStep = res;
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.climbStairs(3) << endl;
    cout << solution.climbStairs(4) << endl;
    cout << solution.climbStairs(5) << endl;
    return 0;
}
