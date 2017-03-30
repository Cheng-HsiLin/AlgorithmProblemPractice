//
//  329_LongestIncreasingPathInAMatrix.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/30/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) { // time: O(m * n); space: (m * n)
        if (matrix.empty() == true) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > memo(m, vector<int>(n, 0));
        int res = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = dfs(matrix, i, j, m, n, memo);
                res = max(res, len);
            }
        }
        return res;
    }
private:
    // Specify four searching directions
    vector<vector<int> > dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int dfs(vector<vector<int> >& matrix, int i, int j, int m, int n, vector<vector<int> >& memo) {
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        int res = 1;
        for (vector<int>& dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            // move outside of the boundary or not increasing
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) {
                continue;
            }
            int len = 1 + dfs(matrix, x, y, m, n, memo);
            res = max(res, len);
        }
        return memo[i][j] = res;
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<int> > matrix({
                               {9,9,4},
                               {6,6,8},
                               {2,1,1}
                              });
    cout << solution.longestIncreasingPath(matrix) << endl; // 1, 2, 6, 9 => 4
    return 0;
}
