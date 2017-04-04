//
//  40_CombinationSumII.cpp
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) { // time: O(n!); space: O(n)
        vector<vector<int> > res;
        if (candidates.empty() || target <= 0) {
            return res;
        }
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtracking(res, cur, candidates, target, 0);
        return res;
    }
private:
    void backtracking(vector<vector<int> >& res, vector<int>& cur, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
            cur.push_back(candidates[i]);
            backtracking(res, cur, candidates, target - candidates[i], i + 1);
            cur.pop_back();
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
                i++;
            }
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({10, 1, 2, 7, 6, 1, 5});
    vector<vector<int> > res = solution.combinationSum2(nums, 8);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
