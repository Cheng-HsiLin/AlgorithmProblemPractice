//
//  11_ContainerWithMostWater.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Two Pointers Method
class Solution {
public:
    int maxArea(vector<int>& height) { // time: O(n); space: O(1)
        int i = 0, j = height.size() - 1, res = 0, h = 0;
        while (i < j) {
            h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            if (height[i] < height[j]) {
                i++;
            } else { // height[i] <= height[j]
                j--;
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> height = {2, 1, 3};
    cout << solution.maxArea(height) << endl;
    return 0;
}
