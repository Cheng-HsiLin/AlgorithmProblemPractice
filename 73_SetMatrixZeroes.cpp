//
//  73_SetMatrixZeroes.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/18/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { // time: O(m * n); space: O(1)
        if (matrix.empty() == true) {
            return;
        }
        int m = matrix.size(), n = matrix[0].size();
        int col0 = 1;
        // 1st column records each row
        // 1st row records each column
        // matrix[0][0] is overlapping, and restores row 0
        // col0 restores column 0
        // Use matrix elements to set states in the 1st row and 1st col from top to down
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col0 = 0;
            }
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        // Use states in the 1st row and 1st col to set matrix elements from down to top
        // because the first row and first column stores information for each row and column
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                if ((matrix[i][0] == 0 || matrix[0][j] == 0) && matrix[i][j] != 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0 == 0 && matrix[i][0] != 0) {
                matrix[i][0] = 0;
            }
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<int> > matrix({
                                {1,3,5,0},
                                {1,2,3,5},
                                {0,3,1,5},
                                {9,7,5,3}
                                });
    solution.setZeroes(matrix);
    for (auto& v : matrix) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
