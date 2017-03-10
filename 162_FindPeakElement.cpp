//
//  162_FindPeakElement.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Binary Search Method
class Solution {
public:
    int findPeakElement(vector<int>& nums) { // time: O(logn); space: O(1)
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l; // return r also works
    }
};

// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) { // time: O(logn); space: O(1)
//         int l = 0, r = nums.size() - 1, mid;
//         while (l <= r) {
//             mid = l + (r - l) / 2;
//             if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
//                 break;
//             } else if (nums[mid] < nums[mid + 1]) {
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }
//         return mid;
//     }
// };

// Test
int main () {
    Solution solution;
    vector<int> nums({1, 2, 3, 1});
    cout << solution.findPeakElement(nums) << endl;
    return 0;
}
