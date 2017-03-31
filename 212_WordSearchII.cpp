//
//  212_WordSearchII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/31/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) { // time: O(mn*4^len); space: O(len)
        vector<string> res;
        if (board.empty() == true || words.empty() == true) {
            return res;
        }
        int m = board.size(), n = board[0].size();
        TrieNode* root = buildTrie(words);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }
private:
    struct TrieNode {
        vector<TrieNode*> next;
        string word;
        TrieNode() : word(""), next(vector<TrieNode*>(26, nullptr)) {}
    };
    // Build the Trie
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* cur = root;
            for (char& c : w) {
                int i = c - 'a';
                if (cur->next[i] == nullptr) {
                    cur->next[i] = new TrieNode();
                }
                cur = cur->next[i];
            }
            cur->word = w;
        }
        return root;
    }
    
    void dfs(vector<vector<char> >& board, int i, int j, TrieNode* cur, vector<string>& res) {
        char c = board[i][j];
        if (c == '#' || cur->next[c - 'a'] == nullptr) {
            return;
        }
        cur = cur->next[c - 'a'];
        if (cur->word.empty() == false) { // found one word
            res.push_back(cur->word);
            cur->word = ""; // to avoid duplication
        }
        board[i][j] = '#'; // mark in order not to reuse the grid
        if (i > 0) {
            dfs(board, i - 1, j, cur, res);
        }
        if (j > 0) {
            dfs(board, i, j - 1, cur, res);
        }
        if (i < board.size() - 1) {
            dfs(board, i + 1, j, cur, res);
        }
        if (j < board[0].size() - 1) {
            dfs(board, i, j + 1, cur, res);
        }
        board[i][j] = c;
    }
};

// Test
int main () {
    Solution solution;
    vector<string> words({"oath","pea","eat","rain"});
    vector<vector<char> > board({
                                {'o','a','a','n'},
                                {'e','t','a','e'},
                                {'i','h','k','r'},
                                {'i','f','l','v'}
                                });
    vector<string> res = solution.findWords(board, words);
    for (string& str : res) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
