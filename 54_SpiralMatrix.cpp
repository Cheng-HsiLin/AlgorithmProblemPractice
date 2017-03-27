//
//  54_SpiralMatrix.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/26/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { // time: O(m * n); space: O(m * n)
        if (matrix.empty() == true) {
            return vector<int>();
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n);
        int up = 0, down = m - 1, left = 0, right = n - 1, idx = 0;
        while (true) {
            // up
            for (int col = left; col <= right; col++) {
                res[idx++] = matrix[up][col];
            }
            if (++up > down) {
                break;
            }
            // right
            for (int row = up; row <= down; row++) {
                res[idx++] = matrix[row][right];
            }
            if (--right < left) {
                break;
            }
            // down
            for (int col = right; col >= left; col--) {
                res[idx++] = matrix[down][col];
            }
            if (--down < up) {
                break;
            }
            // left
            for (int row = down; row >= up; row--) {
                res[idx++] = matrix[row][left];
            }
            if (++left > right) {
                break;
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<int> > matrix({
                                {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}
                                });
    vector<int> res = solution.spiralOrder(matrix);
    for (int& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
