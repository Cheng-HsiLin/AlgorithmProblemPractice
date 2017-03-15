//
//  227_BasicCalculatorII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/14/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Use find_first_not_of() to skip whitespaces
class Solution {
public:
    int calculate(string s) { // time: O(n); space: O(1)
        int res = 0, tmp = 0, num = 0;
        char op = '+', ch;
        for (int i = s.find_first_not_of(' '); i < s.length(); i = s.find_first_not_of(' ', i)) {
            ch = s[i]; // current char
            if (ch >= '0' && ch <= '9') { // ch is a digit
                num = ch - '0';
                // make sure if this digit is followed by other digits
                while (++i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                }
                switch(op) {
                    case '+':
                        tmp += num;
                        break;
                    case '-':
                        tmp -= num;
                        break;
                    case '*':
                        tmp *= num;
                        break;
                    case '/':
                        tmp /= num;
                        break;
                }
            } else { // ch is an operator
                if (ch == '+' || ch == '-') { // start a new tmp calculation once meeting a new '+' or '-'
                    res += tmp;
                    tmp = 0; // reset to 0
                }
                op = s[i++];
            }
        }
        res += tmp;
        return res;
    }
};

// // istringstream Method
// class Solution {
// public:
//     int calculate(string s) { // time: O(n); space: O(1)
//         istringstream in('+' + s + '+');
//         long res = 0, tmp = 0, num = 0;
//         char op;
//         while (in >> op) {
//             if (op == '+' || op == '-') {
//                 res += tmp;
//                 in >> tmp;
//                 tmp *= (44 - op);
//             } else {
//                 in >> num;
//                 if (op == '*') {
//                     tmp *= num;
//                 } else {
//                     tmp /= num;
//                 }
//             }
//         }
//         return res;
//     }
// };

// Test
int main () {
    Solution solution;
    string s1 = "3+2*2", s2 = " 3/2 ", s3 = " 3+5 / 2 ";
    cout << solution.calculate(s1) << endl;
    cout << solution.calculate(s2) << endl;
    cout << solution.calculate(s3) << endl;
    return 0;
}
