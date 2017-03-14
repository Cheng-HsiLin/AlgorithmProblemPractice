//
//  279_PerfectSquares.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/13/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

// // Naive DP Method (Slow)
// class Solution {
// public:
//     int numSquares(int n) { // time: O(n^1.5); space: O(n)
//         vector<int> dp(n + 1, INT_MAX);
//         dp[0] = 0; // 0 is not a perfect square number
//         for (int i = 1; i <= n; i++) {
//             int curMin = INT_MAX;
//             for (int j = 1; j * j <= i; j++) {
//                 curMin = min(curMin, dp[i - j * j] + 1);
//             }
//             dp[i] = curMin;
//         }
//         return dp[n];
//     }
// };

// Static DP Method (Fast)
class Solution {
public:
    int numSquares(int n) { // time: O(n^1.5); space: O(n)
        static vector<int> dp({0});
        while (dp.size() <= n) {
            int m = dp.size();
            int curMin = INT_MAX;
            for (int i = 1; i * i <= m; i++) {
                curMin = min(curMin, dp[m - i * i] + 1);
            }
            dp.push_back(curMin);
        }
        return dp[n];
    }
};

// // Mathematic Method
// class Solution {
// public:
//     int numSquares(int n) { // time: O(n^0.5); space: O(1)
//         // 4 condition: n is the form of 4^k * (8m + 7)
//         while (n % 4 == 0) {
//             n /= 4;
//         }
//         if (n % 8 == 7) {
//             return 4;
//         }
//         // 1 or 2 condition: e.g. 25 = 0^2 + 5^2, it is counted as 1 condition since a == 0
//         for (int a = 0; a * a <= n; a++) {
//             int b = sqrt(n - a * a);
//             if (a * a + b * b == n) {
//                 return a == 0 ? 1 : 2;
//             }
//         }
//         // Other cases: 3 condition
//         return 3;
//     }
// };

// Test
int main () {
    Solution solution;
    vector<vector<char> > board({{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}});
    cout << solution.numSquares(13) << endl; // 4 + 9
    cout << solution.numSquares(12) << endl; // 4 + 4 + 4
    cout << solution.numSquares(25) << endl; // 25
    return 0;
}
