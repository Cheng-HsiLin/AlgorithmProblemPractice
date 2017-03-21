//
//  239_SlidingWindowMaximum.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/20/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { // time: O(n); space: O(n)
        int n = (int) nums.size();
        vector<int> res;
        // keep indices of promising elements in deque
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            // deque window includes [i - k + 1, i]
            while (dq.empty() == false && dq.front() < i - k + 1) {
                dq.pop_front(); // discard those out of i - k + 1
            }
            // If nums[x] < nums[i] and x < i,
            // then nums[x] has no chance to be the max in deque window.
            // Keep the front of deque being the max in the window
            while (dq.empty() == false && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            // The window size less than k is not valid
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1,3,-1,-3,5,3,6,7});
    vector<int> res = solution.maxSlidingWindow(nums, 3);
    for (auto& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
