//
//  125_ValidPalindrome.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/12/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // time: O(n); space: O(1)
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
        }
        return true; // empty string is a palindrome
    }
};

// Test
int main () {
    Solution solution;
    cout << (solution.isPalindrome("A man, a plan, a canal: Panama") ? "True" : "False") << endl;
    cout << (solution.isPalindrome("race a car") ? "True" : "False") << endl;
    return 0;
}
