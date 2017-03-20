//
//  378_KthSmallestElementInASortedMatrix.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/19/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Binary Search Method
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) { // time: O(nlogn); space: O(1); n is the total elements in the matrix
        if (matrix.empty() || k <= 0) {
            return 0;
        }
        int left = matrix[0][0], right = matrix[matrix.size() - 1][matrix[0].size() - 1];
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0, j = matrix[0].size() - 1;
            for (int i = 0; i < matrix.size(); i++) {
                while (j >= 0 && matrix[i][j] > mid) {
                    j--;
                }
                count += (j + 1);
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<int> > matrix({
                                {1,5,9},
                                {10,11,13},
                                {12,13,15}
                                });
    cout << solution.kthSmallest(matrix, 8) << endl;
    return 0;
}
