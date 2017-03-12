//
//  202_HappyNumber.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/12/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <unordered_set>

using namespace std;

// Hashtable Method
class Solution {
public:
    bool isHappy(int n) { // time: O(# of operations before finding the answer * # of digits); space: O(n)
        unordered_set<int> record;
        while (!record.count(n)) { // O(# of operations before finding the answer) for the worst; O(1) for average [unorder_set]
            record.insert(n);
            n = digitSquareSum(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
    }
private:
    int digitSquareSum(int n) {
        int sum = 0, curDigit = 0;
        while(n) {
            curDigit = n % 10;
            sum += curDigit * curDigit;
            n /= 10;
        }
        return sum;
    }
};

// // Floyd Circle Detection Algorithm (Similar to Linked List Cycle Detection)
// class Solution {
// public:
//     bool isHappy(int n) { // O(# of operations before finding the answer * # of digits); space: O(1)
//         int slow = n, fast = n;
//         do {
//             slow = digitSquareSum(slow);
//             fast = digitSquareSum(digitSquareSum(fast));
//             if (fast == 1) {
//                 return true;
//             }
//         } while (slow != fast);
//         return false;
//     }
// private:
//     int digitSquareSum(int n) {
//         int sum = 0, curDigit = 0;
//         while (n) {
//             curDigit = n % 10;
//             n /= 10;
//             sum += curDigit * curDigit;
//         }
//         return sum;
//     }
// };

// Test
int main () {
    Solution solution;
    cout << (solution.isHappy(19) ? "True" : "Fasle") << endl;
    cout << (solution.isHappy(2) ? "True" : "Fasle") << endl;
    cout << (solution.isHappy(13) ? "True" : "Fasle") << endl;
    cout << (solution.isHappy(40) ? "True" : "Fasle") << endl;
    cout << (solution.isHappy(9) ? "True" : "Fasle") << endl;
    return 0;
}
