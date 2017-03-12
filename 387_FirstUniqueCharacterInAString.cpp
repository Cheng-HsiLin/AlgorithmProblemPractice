//
//  387_FirstUniqueCharacterInAString.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/11/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Two-Pass-of-String Method with a vector table to record the occurrence of characters
class Solution {
public:
    int firstUniqChar(string s) { // time: O(n); space: O(1)
        vector<int> record(26);
        // Scan string to build the record table
        for (char& c : s) {
            record[c - 'a']++;
        }
        // Scan string to find the first char which occurs only once
        for (int i = 0; i < s.size(); i++) {
            if (record[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

// // One-Pass-Sring + One-Pass-RecordTable Method
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         vector<pair<int, int> > record(26);
//         int n = s.size();
//         // Scan stirng to build the record table
//         for (int i = 0; i < n; i++) {
//             int idx = s[i] - 'a';
//             record[idx].first++;
//             record[idx].second = i;
//         }
//         int res = n;
//         // Scan record to find the first char which occurs only once
//         for (int i = 0; i < 26; i++) {
//             if (record[i].first == 1) {
//                 res = min(res, record[i].second);
//             }
//         }
//         return res == n ? -1 : res;
//     }
// };

// Test
int main () {
    Solution solution;
    cout << solution.firstUniqChar("leetcode") << endl; // 0
    cout << solution.firstUniqChar("loveleetcode") << endl; // 2
    cout << solution.firstUniqChar("") << endl; // -1
    return 0;
}
