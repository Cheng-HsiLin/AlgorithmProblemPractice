//
//  12_IntegerToRoman.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/09/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// // List all possbile numbers
// class Solution {
// public:
//     string intToRoman(int num) { // time: O(n); space: O(1)
//         vector<string> ones({"","I","II","III","IV","V","VI","VII","VIII","IX"});
//         vector<string> tens({"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"});
//         vector<string> hundreds({"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"});
//         vector<string> thousands({"","M","MM","MMM"});
//         string res = thousands[(num / 1000) % 10] + hundreds[(num / 100) % 10] + tens[(num / 10) % 10] + ones[num % 10];
//         return res;
//     }
// };

// Only list numbers related to 1, 4, 5, 9
class Solution {
public:
    string intToRoman(int num) { // time: O(# of digits); space: O(1)
        string res = "";
        vector<string> symbols({"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"});
        vector<int> values({1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1});
        for (int i = 0; num != 0; i++) {
            while (num >= values[i]) {
                num -= values[i];
                res += symbols[i];
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.intToRoman(99) << endl;
    return 0;
}
