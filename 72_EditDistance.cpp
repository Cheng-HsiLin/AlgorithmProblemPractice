//
//  72_EditDistance.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/11/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// // Naive DP Method with 2D DP table
// class Solution {
// public:
//     int minDistance(string word1, string word2) { // time: O(m * n); space: O(m * n)
//         int m = word1.size(), n = word2.size();
//         vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
//         // initialize the first column
//         for (int i = 1; i <= m; i++) {
//             dp[i][0] = i;
//         }
//         // initialized the first row
//         for (int j = 1; j <= n; j++) {
//             dp[0][j] = j;
//         }
//         for (int i = 1; i <= m; i++) {
//             for (int j = 1; j <= n; j++) {
//                 if (word1[i - 1] == word2[j - 1]) {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 } else {
//                     dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };

// DP Method with Optimized Space
class Solution {
public:
    int minDistance(string word1, string word2) { // time: O(m * n); space: O(min(m, n))
        int m = word1.size(), n = word2.size();
        if (m < n) {
            return minDistance(word2, word1);
        }
        vector<int> dp(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            dp[j] = j;
        }
        int upperLeft = 0; // dp[i - 1][j - 1]
        int upper = 0; // dp[i - 1][j]
        for (int i = 1; i <= m; i++) {
            upperLeft = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; j++) {
                upper = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = upperLeft;
                } else {
                    dp[j] = min(min(dp[j], dp[j - 1]), upperLeft) + 1;
                }
                upperLeft = upper; // the current upper is the next upperLeft
            }
        }
        return dp[n];
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.minDistance("abc", "acd") << endl;
    return 0;
}
