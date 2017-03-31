//
//  84_LargestRectangleInHistogram.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/30/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { // time: O(n); space: O(n)
        heights.push_back(0); // a sentinel node
        stack<int> st;
        int res = 0, i = 0, n = heights.size();
        while (i < n) {
            if (st.empty() == true || heights[i] > heights[st.top()]) {
                st.push(i);
                i++;
            } else {
                int h = heights[st.top()];
                st.pop();
                res = max(res, h * (st.empty() == true ? i : i - st.top() - 1));
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> heights({2,1,5,6,2,3});
    cout << solution.largestRectangleArea(heights) << endl;
    return 0;
}
