//
//  27_RemoveElement.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/03/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Two Pointers Method
class Solution {
public:
    int removeElement(vector<int>& nums, int val) { // time: O(n); space: O(1)
        if (nums.empty() == true) {
            return 0;
        }
        int n = nums.size();
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[start++] = nums[i];
            }
        }
        return start;
    }
};

// // Two Pointers Method (when elements to remove are rare)
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) { // time: O(n); space: O(1)
//         int i = 0, n = nums.size();
//         while (i < n) {
//             if (nums[i] == val) {
//                 nums[i] = nums[n - 1];
//                 n--;
//             } else {
//                 i++;
//             }
//         }
//         return n;
//     }
// };

// Test
int main () {
    Solution solution;
    vector<int> nums({3,2,2,3});
    cout << solution.removeElement(nums, 3) << endl;
    return 0;
}
