//
//  130_SurroundedRegions.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/28/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// DFS Method
class Solution {
public:
    void solve(vector<vector<char>>& board) { // time: O(m * n); space: O(m * n)
        if (board.empty()) {
            return;
        }
        int m = board.size(), n = board[0].size();
        // Mark the 'O's from four borders first
        for (int i = 0; i < m; i++) {
            check(board, i, 0); // first column
            check(board, i, n - 1); // last column
        }
        for (int j = 1; j < n - 1; j++) {
            check(board, 0, j); // first row
            check(board, m - 1, j); // last row
        }
        // Check other 'O's inside the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    void check(vector<vector<char> >& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '#';
            // We can skip the four borderes because we will check them at first
            if (i > 1) {
                check(board, i - 1, j);
            }
            if (j > 1) {
                check(board, i, j - 1);
            }
            if (i + 2 < board.size()) {
                check(board, i + 1, j);
            }
            if (j + 2 < board[0].size()) {
                check(board, i, j + 1);
            }
        }
    }
};

// // BFS Method
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) { // time: O(m * n); space: O(m * n)
//         if (board.empty()) {
//             return;
//         }
//         int m = board.size(), n = board[0].size();
//         for (int i = 0; i < m; i++) {
//             if (board[i][0] == 'O') {
//                 mark(board, i, 0);
//             }
//             if (board[i][n - 1] == 'O') {
//                 mark(board, i, n - 1);
//             }
//         }
//         for (int j = 1; j < n - 1; j++) {
//             if (board[0][j] == 'O') {
//                 mark(board, 0, j);
//             }
//             if (board[m - 1][j] == 'O') {
//                 mark(board, m - 1, j);
//             }
//         }
//         find(board);
//     }
// private:
//     // Mark the 'O' neighbors with '#'
//     void update(vector<vector<char> >& board, queue<pair<int, int> >& toVisit, int r, int c) {
//         int m = board.size(), n = board[0].size();
//         if (r > 1 && board[r - 1][c] == 'O') {
//             board[r - 1][c] = '#';
//             toVisit.push({r - 1, c});
//         }
//         if (c > 1 && board[r][c - 1] == 'O') {
//             board[r][c - 1] = '#';
//             toVisit.push({r, c - 1});
//         }
//         if (r + 2 < m && board[r + 1][c] == 'O') {
//             board[r + 1][c] = '#';
//             toVisit.push({r + 1, c});
//         }
//         if (c + 2 < n && board[r][c + 1] == 'O') {
//             board[r][c + 1] = '#';
//             toVisit.push({r, c + 1});
//         }
//     }
//     // Mark Non-Surrounded Regions
//     void mark(vector<vector<char> >& board, int r, int c) {
//         queue<pair<int, int> > toVisit;
//         toVisit.push({r, c});
//         board[r][c] = '#';
//         while (toVisit.empty() == false) {
//             int num = toVisit.size();
//             for (int i = 0; i < num; i++) {
//                 pair<int, int> cur = toVisit.front();
//                 toVisit.pop();
//                 update(board, toVisit, cur.first, cur.second);
//             }
//         }
//     }
//     // Find the Surrounded Regions
//     void find(vector<vector<char> >& board) {
//         int m = board.size(), n = board[0].size();
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (board[i][j] == '#') {
//                     board[i][j] = 'O';
//                 } else if (board[i][j] == 'O') {
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };

// Test
int main () {
    Solution solution;
    vector<vector<char> > board({
                                {'X','X','X','X'},
                                {'X','O','O','X'},
                                {'X','X','O','X'},
                                {'X','O','X','X'}
                                });
    solution.solve(board);
    for (auto& v : board) {
        for (char& c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
