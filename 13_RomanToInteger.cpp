//
//  13_RomanToInteger.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/14/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) { // time: O(n); space: O(1)
        if (s.empty()) {
            return 0;
        }
        int n = s.size(), res = 0, cur, next;
        for (int i = 0; i < n; i++) {
            cur = conversion(s[i]), next = conversion(s[i + 1]);
            if (i + 1 < n && cur < next) {
                res -= cur;
            } else {
                res += cur;
            }
        }
        return res;
    }
private:
    int conversion(char ch) {
        switch(ch) {
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
            default:
                return 0;
        }
    }
};

// Test
int main () {
    Solution solution;
    string s1 = "XXXXIII", s2 = "IXM", s3 = "";
    cout << solution.romanToInt(s1) << endl;
    cout << solution.romanToInt(s2) << endl;
    cout << solution.romanToInt(s3) << endl;
    return 0;
}
