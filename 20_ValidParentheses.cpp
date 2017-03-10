//
//  20_ValidParentheses.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) { // time: O(n); space: O(n)
        // Validate Input
        if (s.empty()) {
            return true;
        }
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                } else if ((c == ')' && st.top() != '(') || (c == '}' && st.top() != '{') || (c == ']' && st.top() != '[')) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};

// Test
int main () {
    Solution solution;
    cout << (solution.isValid("()[]{}") ? "TRUE" : "FALSE") << endl;
    cout << (solution.isValid(")[{") ? "TRUE" : "FALSE") << endl;
    return 0;
}
