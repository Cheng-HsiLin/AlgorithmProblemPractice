//
//  224_BasicCalculator.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/14/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// // Use stack to restore signs merely
// class Solution {
// public:
//     int calculate(string s) { // time: O(n); space: O(n)
//         int res = 0, num = 0, sign = 1;
//         stack<int> signs;
//         signs.push(sign);
//         for (char& c : s) {
//             if (c >= '0' && c <= '9') {
//                 num = num * 10 + (c - '0');
//             } else if (c == '+' || c == '-') {
//                 res += sign * num;
//                 sign = signs.top() * (c == '+' ? 1 : -1); // the sign for the whole equation
//                 num = 0;
//             } else if (c == '(') {
//                 signs.push(sign);
//             } else if (c == ')') {
//                 signs.pop();
//             }
//         }
//         res += sign * num;
//         return res;
//     }
// };

// Use stack to restore previous res and sign
class Solution {
public:
    int calculate(string s) { // time: O(n); space: O(n)
        int res = 0, num = 0, sign = 1;
        stack<int> st;
        for (char& c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                sign = 1;
                res = 0;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= st.top(); // the sign prior to '('
                st.pop();
                res += st.top(); // the previous res
                st.pop();
            }
        }
        if (num != 0) {
            res += sign * num;
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    string s1 = "1 + 1", s2 = " 2-1 + 2 ", s3 = "(1+(4+5+2)-3)+(6+8)";
    cout << solution.calculate(s1) << endl; // 2
    cout << solution.calculate(s2) << endl; // 3
    cout << solution.calculate(s3) << endl; // 23
    return 0;
}
