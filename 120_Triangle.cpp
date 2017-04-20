//
//  120_Triangle.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/20/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// // Bottom-Up DP Method
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) { // time: O(n^2); space: O(n^2)
//         vector<vector<int> > dp;
//         dp.resize(triangle.size());
//         for (int i = 0; i < triangle.size(); i++) {
//             dp[i].resize(i + 1);
//         }
//         for (int r = triangle.size() - 1; r >= 0; r--) {
//             for (int c = r; c >= 0; c--) {
//                 if (r == triangle.size() - 1) {
//                     dp[r][c] = triangle[r][c];
//                 } else {
//                     dp[r][c] = min(dp[r + 1][c], dp[r + 1][c + 1]) + triangle[r][c];
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };

// Bottom-Up DP Method with Optimized Space Usage
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) { // time: O(n^2); space: O(n)
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for (int r = n - 2; r >= 0; r--) {
            for (int c = 0; c <= r; c++) {
                dp[c] = min(dp[c], dp[c + 1]) + triangle[r][c];
            }
        }
        return dp[0];
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<int> > triangle({{2},{3,4},{6,5,7},{4,1,8,3}});
    cout << solution.minimumTotal(triangle) << endl;
    return 0;
}
