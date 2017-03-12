//
//  118_Pascal'sTriangle.cpp
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
    vector<vector<int>> generate(int numRows) { // time: O(n^2); space: (n^2)
        vector<vector<int> > res(numRows);
        for (int i = 0; i < numRows; i++) {
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<vector<int> > res = solution.generate(5);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
