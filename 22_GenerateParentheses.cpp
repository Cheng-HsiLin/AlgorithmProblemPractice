//
//  22_GenerateParentheses.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/08/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Backtracking Method
class Solution {
public:
    vector<string> generateParenthesis(int n) { // time: O(2^n); space: O(n)
        vector<string> res;
        if (n <= 0) {
            return res;
        }
        string cur;
        helper(res, cur, n, 0);
        return res;
    }
private:
    // n: # of '(' to be put into cur
    // m: # of ')' to be put into cur = # of '(' already put into cur
    void helper(vector<string>& res, string& cur, int n, int m) {
        if (n == 0 && m == 0) {
            res.push_back(cur);
            return;
        }
        if (m > 0) {
            cur.push_back(')');
            helper(res, cur, n, m - 1);
            cur.pop_back();
        }
        if (n > 0) {
            cur.push_back('(');
            helper(res, cur, n - 1, m + 1);
            cur.pop_back();
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<string> res = solution.generateParenthesis(3);
    for (string& str : res) {
        for (char& c : str) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
