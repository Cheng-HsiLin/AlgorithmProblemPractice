//
//  240_Searcha2DMatrixII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { // time: (m + n); space: O(1)
        // validate input
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<int> > matrix({{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}});
    cout << (solution.searchMatrix(matrix, 20) ? "TRUE" : "FASLE") << endl;
    cout << (solution.searchMatrix(matrix, 5) ? "TRUE" : "FASLE") << endl;
    return 0;
}
