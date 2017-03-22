//
//  122_BestTimeToBuyAndSellStockII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/22/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Greedy Method
class Solution {
public:
    int maxProfit(vector<int>& prices) { // time: O(n); space: O(1)
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) {
                res += diff;
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums1({7, 1, 5, 3, 6, 4}), nums2({7, 6, 4, 3, 1});
    cout << solution.maxProfit(nums1) << endl; // 7
    cout << solution.maxProfit(nums2) << endl; // 0
    return 0;
}
