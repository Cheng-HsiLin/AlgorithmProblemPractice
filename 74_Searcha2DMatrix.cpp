//
//  74_Searcha2DMatrix.cpp
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) { // time: O(log(m*n)); space: O(1)
        // Validate Input
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid / n][mid % n] < target) {
                low = mid + 1;
            } else if (matrix[mid / n][mid % n] > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) { // time: O(log(m*n)); space: O(1)
//         // Validate Input
//         if (matrix.empty() || matrix[0].empty()) {
//             return false;
//         }
//         int m = matrix.size(), n = matrix[0].size();
//         int low = 0, high = m * n - 1;
//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             if (matrix[mid / n][mid % n] < target) {
//                 low = mid + 1;
//             } else {
//                 high = mid;
//             }
//         }
//         return matrix[high / n][high % n] == target;
//     }
// };

// Test
int main () {
    Solution solution;
    vector<vector<int> > matrix({{1,   3,  5,  7}, {10, 11, 16, 20}, {23, 30, 34, 50}});
    cout << (solution.searchMatrix(matrix, 21) ? "TRUE" : "FASLE") << endl;
    cout << (solution.searchMatrix(matrix, 5) ? "TRUE" : "FASLE") << endl;
    return 0;
}
