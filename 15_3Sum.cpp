//
//  15_3Sum.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/08/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // time: O(n^2); space: O(n^2)
        vector<vector<int> > res;
        int n = nums.size();
        if (n <= 2) {
            return res;
        }
        sort(nums.begin(), nums.end()); // make the vector non-descending
        for (int i = 0; i < n - 2; i++) {
            // use two pointers
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back(vector<int>({nums[i], nums[j++], nums[k--]}));
                    while (j < k && nums[j] == nums[j - 1]) { // skip duplicates
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) { // skip duplicates
                        k--;
                    }
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    j++;
                }
            }
            while (i < n - 3 && nums[i] == nums[i + 1]) { // skip duplicates
                i++;
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int> > res = solution.threeSum(nums);
    for (vector<int>& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
