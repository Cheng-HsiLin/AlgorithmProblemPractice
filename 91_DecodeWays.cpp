//
//  91_DecodeWays.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/20/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// // bottom-up dynamic programming (naive)
// class Solution {
// public:
//     int numDecodings(string s) { // time: O(n); space: O(n)
//         if (s.empty()) {
//             return 0;
//         }
//         int n = s.length();
//         // dp[i]: # of ways to decode for substring(i, end)
//         vector<int> dp(n + 1, 0);
//         dp[n] = 1;
//         // If the last character is '0', it cannot be used as a code.
//         // It has to be a part of another code.
//         dp[n - 1] = s[n - 1] != '0' ? 1 : 0;

//         for (int i = n - 2; i >= 0; i--) {
//             if (s[i] != '0') {
//                 dp[i] += dp[i + 1];
//             }
//             if ((s[i] == '2' && s[i + 1] <= '6') || s[i] == '1') {
//                 dp[i] += dp[i + 2];
//             }
//         }
//         return dp[0];
//     }
// };

// // bottom-up dynamic programming (optimized)
// class Solution {
// public:
//     int numDecodings(string s) { // time: O(n); space: O(1)
//         if (s.empty() || s[0] == '0') {
//             return 0;
//         }
//         int n = s.length();
//         if (n == 1) {
//             return 1;
//         }
//         // f2: # of decode ways of s[i+2...end]
//         // f1: # of decode ways of s[i+1...end]
//         int f2 = 1;
//         int f1 = s[n - 1] != '0' ? 1 : 0;
//         int num;
//         for (int i = n - 2; i >= 0; i--) {
//             num = 0;
//             if (s[i] != '0') {
//                 num += f1;
//             }
//             if ((s[i] == '2' && s[i + 1] <= '6') || s[i] == '1') {
//                 num += f2;
//             }
//             f2 = f1;
//             f1 = num;
//         }
//         return num;
//     }
// };

// // top-down dynamic programming (naive)
// class Solution {
// public:
//     int numDecodings(string s) { // time: O(n); space: O(n)
//         int n = s.length();
//         if (n == 0 || s[0] =='0') {
//             return 0;
//         }
//         vector<int> dp(n + 1, 0);
//         // the empty string will have one way to decode
//         dp[0] = 1;
//         dp[1] = s[0] != '0' ? 1 : 0;
//         for (int i = 2; i <= n; i++) {
//             // can be used alone as a code
//             if (s[i - 1] != '0') {
//                 dp[i] += dp[i - 1];
//             }
//             // can be a part of another code
//             if (s[i - 2] == '2' && s[i - 1] <= '6' || s[i - 2] == '1') {
//                 dp[i] += dp[i - 2];
//             }
//         }
//         return dp[n];
//     }
// };

// top-down dynamic programming (optimized)
class Solution {
public:
    int numDecodings(string s) { // time: O(n); space: O(1)
        int n = s.length();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        // f2: # of decode ways of s[0...i-2]
        // f1: # of decode ways of s[0...i-1]
        int f2 = 1;
        int f1 = s[0] != '0' ? 1 : 0;
        int num = 0;
        for (int i = 2; i <= n; i++) {
            num = 0;
            // zero cannot be used separately
            if (s[i - 1] != '0') {
                num += f1;
            }
            if ((s[i - 2] == '2' && s[i - 1] <= '6') || s[i - 2] == '1') {
                num += f2;
            }
            f2 = f1;
            f1 = num;
        }
        return num;
    }
};

// Test
int main () {
    Solution solution;
    string s = "12";
    cout << solution.numDecodings(s) << endl;
    return 0;
}
