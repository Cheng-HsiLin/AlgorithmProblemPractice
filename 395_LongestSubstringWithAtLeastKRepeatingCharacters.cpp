//
//  395_LongestSubstringWithAtLeastKRepeatingCharacters.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/22/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Recursive Divide-And-Conquer Method
class Solution {
public:
    int longestSubstring(string s, int k) { // time: O(n^2); space: O(n)
        int n = s.length();
        if (n == 0 || n < k) {
            return 0;
        }
        if (k == 0) {
            return n;
        }
        // record the occurrence of each char
        vector<int> record(26, 0);
        for (char c : s) {
            record[c - 'a']++;
        }
        // Find the first char which appears less than k times.
        // It is the char which is not counted in the result
        int i = 0;
        while (i < n && record[s[i] - 'a'] >= k) {
            i++;
        }
        if (i == n) {
            return n;
        }
        // Separate the string into two parts
        int left = longestSubstring(s.substr(0, i), k);
        int right = longestSubstring(s.substr(i + 1), k);
        return max(left, right);
    }
};

// // Improved Naive Quadratic Method
// class Solution {
// public:
//     int longestSubstring(string s, int k) { // time: O(n^2); space: O(1)
//         int maxLen = 0, n = s.length();
//         for (int first = 0; first + k <= n; ) {
//             vector<int> record(26, 0);
//             int mask = 0;
//             int maxLast = first;
//             for (int last = first; last < n; last++) {
//                 int i = s[last] - 'a';
//                 record[i]++;
//                 if (record[i] < k) {
//                     mask |= (1 << i);
//                 } else {
//                     mask &= (~(1 << i));
//                 }
//                 if (mask == 0) {
//                     maxLen = max(maxLen, last - first + 1);
//                     maxLast = last;
//                 }
//             }
//             first = maxLast + 1;
//         }
//         return maxLen;
//     }
// };

// Test
int main () {
    Solution solution;
    string s1 = "aaabb", s2 = "ababbc";
    cout << solution.longestSubstring(s1, 3) << endl;
    cout << solution.longestSubstring(s2, 2) << endl;
    return 0;
}
