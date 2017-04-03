//
//  9_PalindromeNumber.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/03/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) { // time: O(# of digits); space: O(1)
        // a negative number cannot be a palindrome
        if ( x < 0 || (x != 0 && x % 10 == 0) ) {
            return false;
        }
        int y = 0;
        while (x > y) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return (x == y) || ( x == (y / 10) );
    }
};

// Test
int main () {
    Solution solution;
    cout << (solution.isPalindrome(19191) ? "True" : "False") << endl;
    cout << (solution.isPalindrome(1) ? "True" : "False") << endl;
    cout << (solution.isPalindrome(-1) ? "True" : "False") << endl;
    return 0;
}
