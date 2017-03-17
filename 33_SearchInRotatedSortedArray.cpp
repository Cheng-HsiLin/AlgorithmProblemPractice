//
//  33_SearchInRotatedSortedArray.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/17/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) { // time: (logn); space: O(1)
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) { // the first half is sorted
                if (nums[left] <= target && target < nums[mid]) { // target is located in [left, mid)
                    right = mid - 1;
                } else { // target is located in (mid, right]
                    left = mid + 1;
                }
            } else { // the second half is sorted
                if (nums[mid] < target && target <= nums[right]) { // target is located in (mid, right]
                    left = mid + 1;
                } else { // target is located in [left, mid)
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({4,5,6,7,0,1,2,3});
    cout << solution.search(nums, 6) << endl;
    return 0;
}
