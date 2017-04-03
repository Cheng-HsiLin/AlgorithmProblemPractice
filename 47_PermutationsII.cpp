//
//  47_PermutationsII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/02/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) { // time: O(n!); space: O(n)
        vector<vector<int> > res;
        if (nums.empty() == true) {
            return res;
        }
        vector<int> cur;
        vector<bool> isVisited(nums.size(), false);
        // in order to avoid duplicates
        sort(nums.begin(), nums.end());
        backtracking(res, cur, isVisited, nums);
        return res;
    }
private:
    void backtracking(vector<vector<int> >& res, vector<int>& cur, vector<bool>& isVisited, vector<int>& nums) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (isVisited[i] == false) {
                isVisited[i] = true;
                cur.push_back(nums[i]);
                backtracking(res, cur, isVisited, nums);
                cur.pop_back();
                isVisited[i] = false;
                // skip duplicates
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    i++;
                }
            }
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1,1,2});
    vector<vector<int> > res = solution.permuteUnique(nums);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
