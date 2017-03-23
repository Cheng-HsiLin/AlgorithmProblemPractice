//
//  289_GameOfLife.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/22/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) { // time: O(m * n); space: O(1)
        if (board.empty() == true) {
            return;
        }
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int I = max(i - 1, 0); I < min(i + 2, m); I++) {
                    for (int J = max(j - 1, 0); J < min(j + 2, n); J++) {
                        count += board[I][J] & 1; // count the current state
                    }
                }
                count -= board[i][j] & 1;
                if (board[i][j] == 1 && (count == 2 || count == 3)) {
                    board[i][j] = 3; // make the second bit as 1: 01->11
                }
                if (board[i][j] == 0 && count == 3) {
                    board[i][j] = 2; // make the second bit as 1: 00->10
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1; // get the next state
            }
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<int> > board({
                                {1,0,1},
                                {1,1,0},
                                {0,1,1}
                                });
    solution.gameOfLife(board);
    for (auto& v : board) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
