//
//  131_PalindromePartitioning.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/22/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) { // time: O(n^3); space: O(n^2)
        vector<vector<string> > res;
        if (s.empty() == true) {
            return res;
        }
        vector<string> cur;
        getPartition(s, 0, cur, res);
        return res;
    }
private:
    void getPartition(string& s, int idx, vector<string>& cur, vector<vector<string> >& res) {
        if (idx == s.length()) {
            res.push_back(cur);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            int l = idx, r = i;
            while (l < r && s[l] == s[r]) {
                l++;
                r--;
            }
            if (l >= r) {
                cur.push_back(s.substr(idx, i - idx + 1));
                getPartition(s, i + 1, cur, res);
                cur.pop_back();
            }
        }
    }
};

// Test
int main () {
    Solution solution;
    string s = "aab";
    vector<vector<string> > res = solution.partition(s);
    for (auto& v : res) {
        for (string& str : v) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
