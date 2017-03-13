//
//  79_WordSearch.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/13/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Recursive Backtracking Method
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) { // time: O(mn*(4^len)); space: O(mn)
        if (word.empty() || board.empty() || board[0].empty()) {
            return false;
        }
        int m = board.size(), n = board[0].size(), len = word.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtracking(board, i, j, word, 0, m, n, len)) {
                    return true; // Found
                }
            }
        }
        return false; // Not found
    }
private:
    bool backtracking(vector<vector<char>>& board, int row, int col, string& word, int start, int m, int n, int len) {
        char curChar = board[row][col];
        bool res = false;
        if (curChar != word[start]) {
            return false;
        }
        if (start == len - 1) {
            return true;
        }
        board[row][col] = '*';
        if (row) {
            res = backtracking(board, row - 1, col, word, start + 1, m, n, len);
        }
        if (!res && row < m - 1) {
            res = backtracking(board, row + 1, col, word, start + 1, m, n, len);
        }
        if (!res && col) {
            res = backtracking(board, row, col - 1, word, start + 1, m, n, len);
        }
        if (!res && col < n - 1) {
            res = backtracking(board, row, col + 1, word, start + 1, m, n, len);
        }
        board[row][col] = curChar;
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<char> > board({{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}});
    cout << (solution.exist(board, "ABCCED") ? "True" : "False") << endl;
    cout << (solution.exist(board, "SEE") ? "True" : "False") << endl;
    cout << (solution.exist(board, "ABCB") ? "True" : "False") << endl;
    return 0;
}
