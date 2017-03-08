//
//  322_CoinChange.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// // Top-Down DP Method
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) { // time: (n * amount); space: O(amount)
//         if (amount < 1) {
//             return 0;
//         }
//         vector<int> dp(amount);
//         return coinChange(coins, amount, dp);
//     }
// private:
//     int coinChange(vector<int>& coins, int amount, vector<int>& dp) {
//         if (amount < 0) {
//             return -1;
//         }
//         if (amount == 0) {
//             return 0;
//         }
//         if (dp[amount - 1] != 0) {
//             return dp[amount - 1];
//         }
//         int res = INT_MAX;
//         for (int coin : coins) {
//             int curMin = coinChange(coins, amount - coin, dp);
//             if (curMin >= 0 && curMin < res) {
//                 res = curMin + 1;
//             }
//         }
//         dp[amount - 1] = (res == INT_MAX) ? -1 : res;
//         return dp[amount - 1];
//     }
// };

// Bottom-Up DP Method with Optimized Space
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { // time: (n * amount); space: O(amount)
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // no amount => no coin
        for (int& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// Test
int main () {
    Solution solution;
    vector<int> coins = {1, 2, 5};
    cout << solution.coinChange(coins, 11) << endl;
    return 0;
}
