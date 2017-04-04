//
//  18_4Sum.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/04/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) { // time: O(n^3); space: O()
        vector<vector<int> > res;
        int n = nums.size();
        // Invalid input
        if (n <= 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            // the possible smallest sum > target, invalid
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            // skip duplicates or find a bigger nums[i]
            if ((i > 0 && nums[i] == nums[i - 1]) || (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                // the possible smallest sum > target, invalid
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                // skip duplicates or find a bigger nums[j]
                if ((j > i + 1 && nums[j] == nums[j - 1]) || (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)) {
                    continue;
                }
                // two pointers
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        res.push_back(vector<int>({nums[i], nums[j], nums[k++], nums[l--]}));
                        while (k < l && nums[k] == nums[k - 1]) { // skip duplicates
                            k++;
                        }
                        while (k < l && nums[l] == nums[l + 1]) { // skip duplicates
                            l--;
                        }
                    } else if (sum > target) {
                        l--;
                        while (k < l && nums[l] == nums[l + 1]) { // skip duplicates
                            l--;
                        }
                    } else {
                        k++;
                        while (k < l && nums[k] == nums[k - 1]) { // skip duplicates
                            k++;
                        }
                    }
                }
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1, 0, -1, 0, -2, 2});
    vector<vector<int> > res = solution.fourSum(nums, 0);
    for (auto& v : res) {
        for (int& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
