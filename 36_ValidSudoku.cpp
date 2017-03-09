//
//  36_ValidSudoku.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/08/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// // Use 3 2D matrix to record occurrence
// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) { // time: O(# of grids); space: O(# of grids)
//         vector<vector<int> > rowCheck(9, vector<int>(9, 0)); // check each row
//         vector<vector<int> > colCheck(9, vector<int>(9, 0)); // check each column
//         vector<vector<int> > boxCheck(9, vector<int>(9, 0)); // check each 3x3 box
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 if (board[i][j] != '.') {
//                     int num = board[i][j] - '0' - 1; // number range: 1-9 but index range: 0-8
//                     int k = (i / 3) * 3 + (j / 3); // board[i][j] is located at the kth box
//                     if (rowCheck[i][num] || colCheck[j][num] || boxCheck[k][num]) {
//                         return false;
//                     }
//                     rowCheck[i][num] = colCheck[j][num] = boxCheck[k][num] = 1;
//                 }
//             }
//         }
//         return true;
//     }
// };

// Bit Manipulation (Optimized Space)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) { // time: O(# of grids); space: O((# of grids) ^ (1/2))
        vector<short> rowCheck(9, 0); // check each row
        vector<short> colCheck(9, 0); // check each column
        vector<short> boxCheck(9, 0); // check each 3x3 box
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int idx = 1 << (board[i][j] - '0' - 1); // number range: 1-9 but index range: 0-8
                    int k = (i / 3) * 3 + (j / 3); // board[i][j] is located at the kth box
                    if (rowCheck[i] & idx || colCheck[j] & idx || boxCheck[k] & idx) {
                        return false;
                    }
                    rowCheck[i] |= idx;
                    colCheck[j] |= idx;
                    boxCheck[k] |= idx;
                }
            }
        }
        return true;
    }
};
