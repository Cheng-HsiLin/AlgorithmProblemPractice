//
//  119_Pascal'sTriangleII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/11/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) { // time: O(n^2); space: O(n)
        vector<int> res(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> res = solution.getRow(4);
    for (int& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
