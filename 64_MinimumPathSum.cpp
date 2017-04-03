//
//  64_MinimumPathSum.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/03/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// // Naive DP Method
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) { // time: O(m * n); space: O(m * n)
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int> > dp(m, vector<int>(n, 0));
//         dp[0][0] = grid[0][0];
//         // First Row
//         for (int j = 1; j < n; j++) {
//             dp[0][j] = dp[0][j - 1] + grid[0][j];
//         }
//         // First Column
//         for (int i = 1; i < m; i++) {
//             dp[i][0] = dp[i - 1][0] + grid[i][0];
//         }

//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// Optimized Space DP Method
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) { // time: O(m * n); space: O(m)
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(m, grid[0][0]);
        // First Column
        for (int i = 1; i < m; i++) {
            dp[i] = dp[i - 1] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0] += grid[0][j];
            for (int i = 1; i < m; i++) {
                dp[i] = grid[i][j] + min(dp[i - 1], dp[i]);
            }
        }
        return dp[m - 1];
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<int> > grid({
                              {1,2,3},
                              {3,3,1},
                              {2,1,2}
                              });
    cout << solution.minPathSum(grid)<< endl; // 9
    return 0;
}
