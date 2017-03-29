//
//  139_WordBreak.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/28/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Bottom-Up DP Method
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) { // time: O(n^2); space: O(n)
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        // dp[i] means whether a valid word (sequence) ends at ith char in s
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] == true) {
                    string word = s.substr(j, i - j);
                    if (dict.count(word) != 0) {
                        dp[i] = true;
                        break; // go to the next i
                    }
                }
            }
        }
        return dp[n];
    }
};

// // Top-Down DP (DFS + Memoization) Method
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) { // time: O(n^2); space: O(n)
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());
//         vector<int> memo(s.size() + 1, -1); // 1: true, 0: false, -1: unchecked
//         return helper(0, s, dict, memo);
//     }
// private:
//     bool helper(int start, string& s, unordered_set<string>& dict, vector<int>& memo) {
//         int n = s.size();
//         if (start == n) {
//             return 1;
//         }
//         if (memo[start] != -1) {
//             return memo[start];
//         }
//         string word;
//         for (int i = start; i < n; i++) {
//             word += s[i];
//             if (dict.count(word) != 0 && helper(i + 1, s, dict, memo) == true) {
//                 return memo[start] = 1;
//             }
//         }
//         return memo[start] = 0;
//     }
// };

// // Trie Data Structure Method
// struct DictNode {
//     bool isWord;
//     vector<DictNode*> next;
//     DictNode(bool b = false) : isWord(b) {
//         next.resize(26);
//     }
// };

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) { // time: O(n^2); space: O(n)
//         buildDict(wordDict);
//         int n = s.size();
//         vector<bool> dp(n + 1, false);
//         dp[0] = true;
//         for (int i = 0; i < n; i++) {
//             if (dp[i] == false) {
//                 continue;
//             }
//             DictNode* p = dict;
//             int j = i;
//             while (j < n && p->next[s[j] - 'a'] != nullptr) {
//                 p = p->next[s[j++] - 'a'];
//                 if (p->isWord == true) {
//                     dp[j] = true;
//                 }
//             }
//             if (dp[n] == true) {
//                 return true;
//             }
//         }
//         return false;
//     }
// private:
//     DictNode* dict;

//     void buildDict(vector<string>& wordDict) {
//         dict = new DictNode();
//         DictNode* p;
//         for (auto& w : wordDict) {
//             p = dict;
//             for (auto& c : w) {
//                 DictNode* &next = p->next[c - 'a'];
//                 if (next == nullptr) {
//                     next = new DictNode();
//                 }
//                 p = next;
//             }
//             p->isWord = true;
//         }
//     }
// };

// Test
int main () {
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict({"leet", "code"});
    cout << (solution.wordBreak(s, wordDict) ? "True" : "False") << endl;
    return 0;
}
