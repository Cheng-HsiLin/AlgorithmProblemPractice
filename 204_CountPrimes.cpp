//
//  204_CountPrimes.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/18/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) { // time: O(n*log(log(n))); space: O(n)
        vector<bool> isPrime(n, true);
        // only need to consider factors up to √n
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i] == false) {
                continue;
            }
            // if the current number is p, we can always mark off multiples of p starting at p^2
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        int res = 0;
        // check how many numbers left as true
        for (int k = 2; k < n; k++) {
            if (isPrime[k] == true) {
                res++;
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    cout << solution.countPrimes(10) << endl; // 2, 3, 5, 7 => ans = 4
    return 0;
}
