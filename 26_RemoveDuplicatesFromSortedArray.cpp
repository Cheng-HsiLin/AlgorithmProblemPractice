//
//  26_RemoveDuplicatesFromSortedArray.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/14/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) { // time: O(n); space: O(1)
//         if (nums.empty()) {
//             return 0;
//         }
//         int n = nums.size(), i = 0, j = 0;
//         while (i < n) {
//             while (nums[i] == nums[i + 1]) {
//                 i++;
//             }
//             nums[j++] = nums[i++];
//         }
//         return j;
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) { // time: O(n); space: O(1)
        if (nums.empty()) {
            return 0;
        }
        int pos = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[pos - 1] != nums[i]) {
                nums[pos++] = nums[i];
            }
        }
        return pos;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1, 1, 2});
    cout << solution.removeDuplicates(nums) << endl;
    vector<int> nums1({});
    cout << solution.removeDuplicates(nums1) << endl;
    return 0;
}
