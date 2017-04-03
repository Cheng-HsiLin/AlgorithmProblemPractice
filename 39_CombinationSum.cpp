//
//  39_CombinationSum.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/03/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { // time: O(n!); space: O(n)
        vector<vector<int> > res;
        if (candidates.empty() == true || target <= 0) {
            return res;
        }
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtracking(res, cur, 0, candidates, target);
        return res;
    }
private:
    void backtracking(vector<vector<int> >& res, vector<int>& cur, int start, vector<int>& candidates, int target) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        // Checking if target is larger than or equal to candidates[i] help prune the recursion
        for (int i = start; i < candidates.size() && target >= candidates[i]; i++) {
            cur.push_back(candidates[i]);
            backtracking(res, cur, i, candidates, target - candidates[i]);
            cur.pop_back();
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({2, 3, 6, 7});
    vector<vector<int> > res = solution.combinationSum(nums, 7);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
