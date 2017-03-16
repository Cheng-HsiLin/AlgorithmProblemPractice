//
//  238_ProductOfArrayExceptSelf.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/15/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// // Two Pass Method
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) { // time: O(2n); space: O(n)
//         int n = (int) nums.size();
//         vector<int> res(n, 1);
//         // left to right
//         for (int i = 1; i < n; i++) {
//             res[i] = res[i - 1] * nums[i - 1];
//         }
//         // right to left
//         for (int j = n - 1, r = 1; j >= 0; r *= nums[j--]) {
//             res[j] *= r;
//         }
//         return res;
//     }
// };

// One Pass Method
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) { // time: O(n); space: O(n)
        if (nums.empty()) {
            return vector<int>({});
        }
        int n = (int) nums.size(), left = 1, right = 1;
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            res[i] *= left;
            left *= nums[i];
            res[n - 1 - i] *= right;
            right *= nums[n - 1 - i];
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1,2,3,4});
    vector<int> res = solution.productExceptSelf(nums);
    for (int& i : res) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> nums1({0, 0});
    vector<int> res1 = solution.productExceptSelf(nums1);
    for (int& i : res1) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
