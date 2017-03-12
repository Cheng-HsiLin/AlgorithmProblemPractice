//
//  287_FindTheDuplicateNumber.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/11/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// // Binary Search Method
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) { // time: O(nlogn); space: O(1)
//         int low = 1, high = nums.size();
//         while (low < high) { // O(logn)
//             int mid = low + (high - low) / 2, count = 0;
//             for (int& num : nums) { // O(n)
//                 if (num <= mid) {
//                     count++;
//                 }
//             }
//             if (count <= mid) {
//                 low = mid + 1;
//             } else {
//                 high = mid;
//             }
//         }
//         return low;
//     }
// };

// Two Pointers Method (Similar to finding the cycle in Linked List)
class Solution {
public:
    int findDuplicate(vector<int>& nums) { // time: O(n); space: O(1)
        if (nums.size() <= 1) {
            return -1; // invalid input
        }
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1,2,3,4,5,5});
    cout << solution.findDuplicate(nums) << endl;
    vector<int> nums1({1});
    cout << solution.findDuplicate(nums1) << endl;
    return 0;
}
