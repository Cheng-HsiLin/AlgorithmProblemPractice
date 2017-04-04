//
//  90_SubsetsII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/04/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) { // time: O(2^n); space: O(2^n)
        vector<vector<int> > res;
        if (nums.empty()) {
            return res;
        }
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtracking(res, cur, nums, 0);
        return res;
    }
private:
    void backtracking(vector<vector<int> >& res, vector<int>& cur, vector<int>& nums, int start) {
        res.push_back(cur);
        for (int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            backtracking(res, cur, nums, i + 1);
            cur.pop_back();
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1,2,2});
    vector<vector<int> > res = solution.subsetsWithDup(nums);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
