//
//  17_LetterCombinationsOfAPhoneNumber.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/08/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// // Backtracking Method
// class Solution {
// public:
//     vector<string> letterCombinations(string digits) { // time: O(4^(# of digits)); space: O(# of digits)
//         vector<string> res;
//         if (digits.empty()) {
//             return res;
//         }
//         string cur;
//         // no corresponding characters for 0 and 1
//         vector<string> dict({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
//         backtracking(res, cur, dict, digits, 0);
//         return res;
//     }
// private:
//     void backtracking(vector<string>& res, string& cur, vector<string>& dict, string& digits, int pos) {
//         if (pos == digits.size()) {
//             res.push_back(cur);
//             return;
//         }
//         string str = dict[digits[pos] - '0'];
//         for (int i = 0; i < str.size(); i++) {
//             cur.push_back(str[i]);
//             backtracking(res, cur, dict, digits, pos + 1);
//             cur.pop_back();
//         }
//     }
// };

// Iterative Method
class Solution {
public:
    vector<string> letterCombinations(string digits) { // time: O(4 ^ (# of digits)); space: O(1)
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        vector<string> dict({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        res.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            vector<string> tmp;
            string str = dict[digits[i] - '0'];
            for (int j = 0; j < str.size(); j++) {
                for (int k = 0; k < res.size(); k++) {
                    tmp.push_back(res[k] + str[j]);
                }
            }
            res = tmp;
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<string> res = solution.letterCombinations("23");
    for (string& str : res) {
        for (char& c : str) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
