//
//  179_LargestNumber.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/26/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) { // time: O(nlogn); space: O(n)
        if (nums.empty() == true) {
            return "";
        }
        int n = nums.size();
        vector<string> strs(n);
        for (int i = 0; i < n; i++) {
            strs[i] = to_string(nums[i]);
        }
        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) { return s1 + s2 > s2 + s1; });
        if (strs[0][0] == '0') {
            return "0";
        }
        string res;
        for (const string& str : strs) {
            res += str;
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({3, 30, 34, 5, 9});
    cout << solution.largestNumber(nums) << endl; // 9534330
    vector<int> nums1({0, 0, 0});
    cout << solution.largestNumber(nums1) << endl; // 0
    return 0;
}
