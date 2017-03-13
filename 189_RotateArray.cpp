//
//  189_RotateArray.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/13/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// // Rotate after copying nums to an extra tmp vector (Two-Pass Method)
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) { // time: (2n); space: O(n)
//         if (nums.empty() || k <= 0) {
//             return;
//         }
//         vector<int> tmp(nums.begin(), nums.end());
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             nums[(i + k) % n] = tmp[i];
//         }
//     }
// };

// // Reverse all the n elements, the first k elements, and then the last n - k elements
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) { // time: O(2n); space: O(1)
//         int n = nums.size();
//         k %= n;
//         reverse(nums.begin(), nums.end());
//         reverse(nums.begin(), nums.begin() + k);
//         reverse(nums.begin() + k, nums.end());
//     }
// };

// Cyclic Replacement Method
// Start from one element and keep rotating until we have rotated n different elements
class Solution {
public:
    void rotate(vector<int>& nums, int k) { // time: O(n); space: O(1)
        int n = nums.size();
        k %= n;
        int count = 0;
        for (int start = 0; count < n; start++) {
            int cur = start;
            int prev = nums[start];
            do {
                int next = (cur + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                cur = next;
                count++;
            } while (cur != start);
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1,2,3,4,5,6,7});
    solution.rotate(nums, 3);
    for (int& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
