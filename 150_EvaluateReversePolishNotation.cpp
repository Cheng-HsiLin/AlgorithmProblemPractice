//
//  150_EvaluateReversePolishNotation.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/28/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) { // time: O(n); space: O(n)
        stack<int> st;
        int op1, op2;
        for (auto& str : tokens) {
            if (str != "+" && str != "-" && str != "*" && str != "/") {
                st.push(stoi(str));
            } else {
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                if (str == "+") {
                    st.push(op1 + op2);
                } else if (str == "-") {
                    st.push(op1 - op2);
                } else if (str == "*") {
                    st.push(op1 * op2);
                } else if (str == "/") {
                    st.push(op1 / op2);
                }
            }
        }
        return st.top();
    }
};

// Test
int main () {
    Solution solution;
    vector<string> str1({"2", "1", "+", "3", "*"}), str2({"4", "13", "5", "/", "+"});
    cout << solution.evalRPN(str1) << endl; // 9
    cout << solution.evalRPN(str2) << endl; // 6
    cout << endl;
    return 0;
}
