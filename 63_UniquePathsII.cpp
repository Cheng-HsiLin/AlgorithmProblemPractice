//
//  63_UniquePathsII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/03/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// // Naive DP Method
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { // time: O(m * n); space: O(m * n)
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//         vector<vector<int> > dp(m, vector<int>(n, 0));
//         dp[0][0] = (obstacleGrid[0][0] == 0 ? 1 : 0);
//         // First column
//         for (int i = 1; i < m; i++) {
//             dp[i][0] = (dp[i - 1][0] == 1 && obstacleGrid[i][0] == 0) ? 1 : 0;
//         }
//         // First row
//         for (int j = 1; j < n; j++) {
//             dp[0][j] = (dp[0][j - 1] == 1 && obstacleGrid[0][j] == 0) ? 1 : 0;
//         }

//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 if (obstacleGrid[i][j] == 1) {
//                     dp[i][j] = 0;
//                 } else {
//                     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//                 }
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// Optimized Space DP Method
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { // time: O(m * n); space: O(n)
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<int> > obstacleGrid({
                                      {0,0,0},
                                      {0,1,0},
                                      {0,0,0}
                                      });
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
