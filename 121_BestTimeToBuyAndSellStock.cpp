//
//  121_BestTimeToBuyAndSellStock.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/22/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// // Greedy Method
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) { // time: O(n); space: O(1)
//         int minPrice = INT_MAX;
//         int maxProfit = 0;
//         for (int& num : prices) {
//             if (num < minPrice) {
//                 minPrice = num;
//             } else {
//                 maxProfit = max(maxProfit, num - minPrice);
//             }
//         }
//         return maxProfit;
//     }
// };

// DP Method
class Solution {
public:
    int maxProfit(vector<int>& prices) { // time: O(n); space: O(1)
        if (prices.empty() == true) {
            return 0;
        }
        int cur = 0, res = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            cur = max(cur + prices[i + 1] - prices[i], 0);
            res = max(res, cur);
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums1({7, 1, 5, 3, 6, 4}), nums2({7, 6, 4, 3, 1});
    cout << solution.maxProfit(nums1) << endl; // 5
    cout << solution.maxProfit(nums2) << endl; // 0
    return 0;
}
