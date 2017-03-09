//
//  200_NumberOfIslands.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/09/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// // DFS Recursive Method
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) { // time: (m * n); space: O(m * n)
//         // Validate Input
//         if (grid.empty() || grid[0].empty()) {
//             return 0;
//         }
//         int res = 0, m = grid.size(), n = grid[0].size();
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == '1') {
//                     dfsMarking(grid, i, j);
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// private:
//     void dfsMarking(vector<vector<char> >& grid, int i, int j) {
//         // Validate Input
//         if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
//             return;
//         }
//         // Mark the grid visited
//         grid[i][j] = '0';
//         dfsMarking(grid, i + 1, j);
//         dfsMarking(grid, i - 1, j);
//         dfsMarking(grid, i, j + 1);
//         dfsMarking(grid, i, j - 1);
//     }
// };

// BFS Iterative Method
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) { // time: O(m * n); space: O(m * n)
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int res = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfsMarking(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
private:
    void bfsMarking(vector<vector<char> >& grid, int x, int y) {
        queue<pair<int, int> > q; // pair(x, y)
        q.push({x, y});
        grid[x][y] = '0';
        while(!q.empty()) {
            x = q.front().first, y = q.front().second;
            q.pop();
            // left
            if (x > 0 && grid[x - 1][y] == '1') {
                q.push({x - 1, y});
                grid[x - 1][y] = '0';
            }
            // right
            if (x < grid.size() - 1 && grid[x + 1][y] == '1') {
                q.push({x + 1, y});
                grid[x + 1][y] = '0';
            }
            // up
            if (y > 0 && grid[x][y - 1] == '1') {
                q.push({x, y - 1});
                grid[x][y - 1] = '0';
            }
            // down
            if (y < grid[0].size() - 1 && grid[x][y + 1] == '1') {
                q.push({x, y + 1});
                grid[x][y + 1] = '0';
            }
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<char> > grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    cout << solution.numIslands(grid) << endl;
    return 0;
}
