//
//  78_Subsets.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/09/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Recursive Backtracking Method
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { // time: O(2^n); space: O(2^n)
        vector<vector<int> > res;
        // Validtate Input
        if (nums.empty()) {
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> cur;
        backtracking(nums, res, cur, 0);
        return res;
    }
private:
    void backtracking(vector<int>& nums, vector<vector<int> >& res, vector<int>& cur, int start) {
        res.push_back(cur);
        for (int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            backtracking(nums, res, cur, i + 1);
            cur.pop_back();
        }
    }
};

// // Iterative Method
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) { // time: O(2^n); space: O(2^n)
//         vector<vector<int> > res(1, vector<int>({}));
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); i++) {
//             int curSize = res.size();
//             for (int j = 0; j < curSize; j++) {
//                 res.push_back(res[j]);
//                 res.back().push_back(nums[i]);
//             }
//         }
//         return res;
//     }
// };

// // Bit Manipulation Method (Less Efficient)
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) { // time: O(n * 2^n); space: O(2^n)
//         sort(nums.begin(), nums.end());
//         int total = pow(2, nums.size());
//         vector<vector<int> > res(total, vector<int>({}));
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = 0; j < total; j++) {
//                 if ((j >> i) & 1) {
//                     res[j].push_back(nums[i]);
//                 }
//             }
//         }
//         return res;
//     }
// };

// Test
int main () {
    Solution solution;
    vector<int> nums({1, 2, 3});
    vector<vector<int> > res = solution.subsets(nums);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
