//
//  48_RotateImage.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/26/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// // STL Function Method
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) { // time: (n^2); space: O(1)
//         reverse(matrix.begin(), matrix.end());
//         int n = matrix.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
//     }
// };

// Self-Implemented Method
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) { // time: O(n^2); space: O(1)
        int n = matrix.size();
        int tmp;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
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
    solution.rotate(matrix);
    for (auto& v : matrix) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
