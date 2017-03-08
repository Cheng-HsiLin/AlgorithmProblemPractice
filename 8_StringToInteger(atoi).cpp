//
//  8_StringToInteger(atoi).cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) { // time: O(n); space: O(1)
        if (str.empty()) {
            return 0;
        }
        int idx = 0, sign = 1, n = str.size();
        // skip whitespaces
        while (isspace(str[idx]) && idx < n) {
            idx++;
        }
        long num = 0;
        // in ASCII code, '+' is 43; '-' is 45
        if (str[idx] == '+' || str[idx] == '-') {
            sign = 44 - str[idx++];
        }
        while (idx < n) {
            if (isdigit(str[idx])) {
                num = num * 10 + (str[idx++] - '0');
            } else {
                return sign * num;
            }
            // beyond int range
            if (num > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
        }
        return sign * num;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.myAtoi("12345") << endl;
    cout << solution.myAtoi("     542  ") << endl;
    cout << solution.myAtoi("2147483648") << endl;
    cout << solution.myAtoi("-2147483649") << endl;
    cout << solution.myAtoi("") << endl;
    return 0;
}
