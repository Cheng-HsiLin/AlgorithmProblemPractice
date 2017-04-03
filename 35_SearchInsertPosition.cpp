//
//  35_SearchInsertPosition.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/02/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { // time: O(logn); space: O(1)
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] == target) {
                return mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1,3,5,6});
    cout << solution.searchInsert(nums, 5) << endl; // 2
    cout << solution.searchInsert(nums, 2) << endl; // 1
    cout << solution.searchInsert(nums, 7) << endl; // 4
    cout << solution.searchInsert(nums, 0) << endl; // 0
    return 0;
}
