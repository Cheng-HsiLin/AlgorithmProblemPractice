//
//  166_FractionToRecurringDecimal.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/22/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) { // time: O(n); space: O(n); n: # of recurring decimals
        if (numerator == 0) {
            return "0";
        }
        string res;
        
        // check the sign of the result
        if (((numerator > 0) ^ (denominator > 0)) == true) {
            res += '-';
        }
        
        // Transform into positive long int type to avoid int overflow
        long numer = (numerator < 0) ? (long) numerator * (-1) : (long) numerator;
        long denom = (denominator < 0) ? (long) denominator * (-1) : (long) denominator;
        
        // Integral
        long integral = numer / denom;
        res += to_string(integral);
        
        // Remainder
        long rmd = numer % denom;
        if (rmd == 0) { // done
            return res;
        }
        res += '.';
        
        rmd *= 10; // for next round calculation
        unordered_map<long, int> mp; // record the position to insert '(' later
        while (rmd != 0) {
            if (mp.count(rmd) != 0) {
                res.insert(mp[rmd], "(");
                res += ')';
                break;
            }
            mp[rmd] = res.size();
            long quotient = rmd / denom;
            res += to_string(quotient);
            rmd = (rmd % denom) * 10; // for next round calculation
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.fractionToDecimal(1, 2) << endl;
    cout << solution.fractionToDecimal(2, 1) << endl;
    cout << solution.fractionToDecimal(2, 3) << endl;
    cout << solution.fractionToDecimal(4, 9) << endl;
    cout << solution.fractionToDecimal(4, 333) << endl;
    return 0;
}
