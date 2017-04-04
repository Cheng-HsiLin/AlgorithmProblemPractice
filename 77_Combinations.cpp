//
//  77_Combinations.cpp
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
    vector<vector<int>> combine(int n, int k) { // time: O(C(n, k)); space: O(k)
        vector<vector<int> > res;
        // Invalid input
        if (n < k) {
            return res;
        }
        vector<int> cur;
        backtracking(res, cur, n, k, 1);
        return res;
    }
private:
    void backtracking(vector<vector<int> >& res, vector<int>& cur, int n, int k, int start) {
        if (k == 0) { // finish one possbile combination
            res.push_back(cur);
            return;
        }
        for (int i = start; i <= n; i++) {
            // # of numbers left is less than k
            if (n - i + 1 < k) {
                return;
            }
            cur.push_back(i);
            backtracking(res, cur, n, k - 1, i + 1);
            cur.pop_back();
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<int> > res = solution.combine(4, 2);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
