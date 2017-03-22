//
//  42_TrappingRainWater.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/21/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// // 3-Pass Method
// class Solution {
// public:
//     int trap(vector<int>& height) { // time: O(n); space: O(n)
//         if (height.empty() == true) {
//             return 0;
//         }
//         int n = height.size();
//         vector<int> maxLeft(n, 0), maxRight(n , 0);
//         // scan from left to right to find the max in the left part
//         // scan from right to left to find the max in the right part
//         for (int i = 1; i < n; i++) {
//             maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
//             maxRight[n - 1 - i] = max(maxRight[n - i], height[n - i]);
//         }
//         int res = 0;
//         // The 3rd pass to add up the water
//         for (int j = 0; j < n; j++) {
//             int h = min(maxLeft[j], maxRight[j]);
//             if (h > height[j]) {
//                 res += h - height[j];
//             }
//         }
//         return res;
//     }
// };

// // 2-Pass Method
// class Solution {
// public:
//     int trap(vector<int>& height) { // time: O(n); space: O(1)
//         // find the max column
//         // separate the histogram into left and right parts
//         if (height.empty()) {
//             return 0;
//         }
//         int n = height.size();
//         int max = 0;
//         for (int i = 0; i < n; i++) {
//             if (height[i] > height[max]) {
//                 max = i;
//             }
//         }
//         int res = 0;
//         for (int j = 0, peak = 0; j < max; j++) {
//             if (height[j] > peak) {
//                 peak = height[j];
//             } else {
//                 res += peak - height[j];
//             }
//         }
//         for (int k = n - 1, peak = 0; k > max; k--) {
//             if (height[k] > peak) {
//                 peak = height[k];
//             } else {
//                 res += peak - height[k];
//             }
//         }
//         return res;
//     }
// };

// One-Pass Method
class Solution {
public:
    int trap(vector<int>& height) { // time: O(n); space: O(1)
        if (height.empty()) {
            return 0;
        }
        int left = 0, right = height.size() - 1;
        int res = 0, maxLeft = 0, maxRight = 0;
        // fix the higher column and flow water from the lower part
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    res += maxLeft - height[left];
                }
                left++;
            } else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    res += maxRight - height[right];
                }
                right--;
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> height({0,1,0,2,1,0,1,3,2,1,2,1}); // 6
    cout << solution.trap(height) << endl;
    return 0;
}
