//
//  171_ExcelSheetColumnNumber.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/13/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) { // time: O(n); space: O(1)
        if (s.empty()) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res = res * 26 + (s[i] - 'A' + 1);
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.titleToNumber("ABC") << endl;
    cout << solution.titleToNumber("AB") << endl;
    return 0;
}
