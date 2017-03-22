//
//  128_LongestConsecutiveSequence.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/21/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) { // time: O(n); space: (n)
        unordered_set<int> record(nums.begin(), nums.end());
        int res = 0;
        for (int& num : nums) {
            if (record.count(num) == 0) {
                continue;
            }
            record.erase(num);
            int prev = num - 1, next = num + 1;
            while (record.count(prev) != 0) {
                record.erase(prev);
                prev--;
            }
            while (record.count(next) != 0) {
                record.erase(next);
                next++;
            }
            res = max(res, next - prev - 1);
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({2, 3, 1, 4});
    cout << solution.longestConsecutive(nums) << endl;
    vector<int> nums1({1, 2, 3, 4, 5});
    cout << solution.longestConsecutive(nums1) << endl;
    vector<int> nums2({100, 4, 200, 1, 3, 2});
    cout << solution.longestConsecutive(nums2) << endl;
    return 0;
}
