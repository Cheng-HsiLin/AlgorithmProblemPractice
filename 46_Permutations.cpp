//
//  46_Permutations.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/08/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// Backtracking Method with a 1D array to record occurrence
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) { // time: (n!); space: O(n)
        vector<vector<int> > res;
        // Invalid Input
        if (nums.empty()) {
            return res;
        }
        vector<int> cur;
        vector<int> isVisited(nums.size(), 0); // record what elements have already occurred before
        backtracking(nums, res, cur, isVisited);
        return res;
    }
private:
    void backtracking(vector<int>& nums, vector<vector<int> >& res, vector<int>& cur, vector<int>& isVisited) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (isVisited[i] == 0) {
                isVisited[i] = 1;
                cur.push_back(nums[i]);
                backtracking(nums, res, cur, isVisited);
                cur.pop_back();
                isVisited[i] = 0;
            }
        }
    }
};

// // Backtracking Method with swap to avoid using another vector to record occurrence
// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) { // time: O(n!); space: O(n)
//         vector<vector<int> > res;
//         if (nums.empty()) {
//             return res;
//         }
//         backtracking(res, 0, nums.size(), nums);
//         return res;
//     }
// private:
//     void backtracking(vector<vector<int> >& res, int start, int end, vector<int>& nums) {
//         if (start >= end) {
//             res.push_back(nums);
//             return;
//         }
//         for (int i = start; i < end; i++) {
//             swap(nums[start], nums[i]);
//             backtracking(res, start + 1, end, nums);
//             swap(nums[start], nums[i]);
//         }
//     }
// };

// Test
int main () {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int> > res = solution.permute(nums);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
