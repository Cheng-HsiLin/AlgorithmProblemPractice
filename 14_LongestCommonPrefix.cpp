//
//  14_LongestCommonPrefix.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { // time: O(length of 1st string in strs * n); space: O(1)
        if (strs.empty()) {
            return "";
        }
        for (int idx = 0; idx < strs[0].size(); idx++) {
            char ch = strs[0][idx];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][idx] != ch) {
                    return strs[0].substr(0, idx);
                }
            }
        }
        return strs[0];
    }
};

// Test
int main () {
    Solution solution;
    vector<string> strs({"aabcd", "aabddd", "aaccd", "acd"});
    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}
