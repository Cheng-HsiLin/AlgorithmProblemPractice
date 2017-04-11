//
//  44_WildcardMatching.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/11/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Two Pointers Method
class Solution {
public:
    bool isMatch(string s, string p) { // time: O(m * n); space: O(1)
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match = -1;
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?') ) { // advances both pointers when characters match or '?' occurs
                i++;
                j++;
            } else if (j < n && p[j] == '*') { // advances the pattern pointer and keep track of the positions when '*' occurs
                asterisk = j++;
                match = i;
            } else if (asterisk != -1) { // current characters don't match and last pattern pointer is '*'
                i = ++match;
                j = asterisk + 1;
            } else { // previous and current pattern pointers are not '*', characters don't match
                return false;
            }
        }
        while (j < n && p[j] == '*') { // check the remaining characters in the pattern
            j++;
        }
        return j == n;
    }
};

// // DP Method with 2D DP Table
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int m = s.length(), n = p.length();
//         vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
//         dp[0][0] = true;

//         for (int j = 1; j <= n; j++) {
//             if (p[j - 1] == '*') {
//                 dp[0][j] = true;
//             } else {
//                 break;
//             }
//         }

//         for (int i = 1; i <= m; i++) {
//             for (int j = 1; j <= n; j++) {
//                 if (p[j - 1] != '*') {
//                     dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
//                 } else { // p[j - 1] == '*'
//                     dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
//                 }
//             }
//         }

//         return dp[m][n];
//     }
// };

// // DP Method with 1D DP vector
// class Solution {
// public:
//     bool isMatch(string s, string p) { // time: O(m * n); space: O(m)
//         int m = s.length(), n = p.length();
//         vector<bool> cur(m + 1, false);
//         cur[0] = true;
//         for (int j = 1; j <= n; j++) {
//             bool pre = cur[0];  // record the value before update
//             cur[0] = (cur[0] && p[j - 1] == '*');
//             for (int i = 1; i <= m; i++) {
//                 bool temp = cur[i]; // record the value before update
//                 if (p[j - 1] != '*') {
//                     cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
//                 } else {
//                     cur[i] = cur[i - 1] || cur[i];
//                 }
//                 pre = temp;
//             }
//         }
//         return cur[m];
//     }
// };

// Test
int main () {
    Solution solution;
    cout << (solution.isMatch("aa", "a") ? "True" : "False") << endl; // False
    cout << (solution.isMatch("aa", "aa") ? "True" : "False") << endl; // True
    cout << (solution.isMatch("aaa", "aa") ? "True" : "False") << endl; // False
    cout << (solution.isMatch("aa", "*") ? "True" : "False") << endl; // True
    cout << (solution.isMatch("aa", "a*") ? "True" : "False") << endl; // True
    cout << (solution.isMatch("aab", "c*a*b") ? "True" : "False") << endl; // False
    return 0;
}
