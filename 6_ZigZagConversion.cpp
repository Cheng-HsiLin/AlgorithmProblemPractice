//
//  6_ZigZagConversion.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) { // time: O(n); space: O(n)
        vector<string> str(numRows, "");
        int i = 0, n = s.length();
        while (i < n) {
            // Vertically down
            for (int j = 0; j < numRows && i < n; j++) {
                str[j].push_back(s[i++]);
            }
            // Obliquely up
            for (int k = numRows - 2; k >= 1 && i < n; k--) {
                str[k].push_back(s[i++]);
            }
        }
        string res = "";
        for (string& ss : str) {
            res += ss;
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}
