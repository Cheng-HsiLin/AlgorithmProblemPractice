//
//  454_4SumII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/13/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) { // time: O(n^2); space: O(n^2)
        unordered_map<int, int> record;
        int res = 0;
        // Build a hashmap for possbile sum from A and B
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                int sum = A[i] + B[j];
                record[sum]++;
            }
        }
        // Search for the target sum from C and D in hashmap
        for (int k = 0; k < C.size(); k++) {
            for (int l = 0; l < D.size(); l++) {
                int target = -(C[k] + D[l]);
                if (record.count(target)) {
                    res += record[target];
                }
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> A({1, 2}), B({-2,-1}), C({-1, 2}), D({0, 2});
    cout << solution.fourSumCount(A, B, C, D) << endl;
    return 0;
}
