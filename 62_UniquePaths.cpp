//
//  62_UniquePaths.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// // Naive DP Method
// class Solution {
// public:
//     int uniquePaths(int m, int n) { // time: (m * n); space: O(m * n)
//         if (m == 0 || n == 0) {
//             return 0;
//         }
//         vector<vector<int> > dp(m, vector<int>(n, 0));
//         for (int i = 0; i < m; i++) { // first column
//             dp[i][0] = 1;
//         }
//         for (int j = 1; j < n; j++) { // first row
//             dp[0][j] = 1;
//         }
//         // from [1][1] to [m-1][n-1]
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// DP Method with Optimized Space
class Solution {
public:
    int uniquePaths(int m, int n) { // time: (m * n); space: O(min(m, n))
        if (m > n) {
            return uniquePaths(n, m);
        }
        vector<int> dp(m, 1);
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++) {
                dp[i] += dp[i - 1];
            }
        }
        return dp[m - 1];
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.uniquePaths(3, 7) << endl;
    cout << solution.uniquePaths(5, 4) << endl;
    return 0;
}
