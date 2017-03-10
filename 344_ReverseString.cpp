//
//  344_ReverseString.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) { // time: O(n); space: O(n)
        string res = s;
        int i = 0, j = s.size() - 1;
        char tmp;
        while (i < j) {
            tmp = res[i];
            res[i++] = res[j];
            res[j--] = tmp;
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.reverseString("hello") << endl;
    cout << solution.reverseString("") << endl;
    return 0;
}
