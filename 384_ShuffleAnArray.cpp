//
//  384_ShuffleAnArray.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/17/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        original = nums;
        res = nums;
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        res = original;
        return res;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() { // time: O(n)
        for (int i = res.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(res[i], res[j]);
        }
        return res;
    }
private:
    vector<int> original;
    vector<int> res;
};

// Test
int main () {
    vector<int> nums({1,2,3,4,5});
    Solution solution(nums);
    vector<int> v1 = solution.shuffle(), v2 = solution.shuffle(), v3 = solution.shuffle();
    vector<int> v = solution.reset();
    for (int& i : v1) {
        cout << i << " ";
    }
    cout << endl;
    for (int& i : v2) {
        cout << i << " ";
    }
    cout << endl;
    for (int& i : v3) {
        cout << i << " ";
    }
    cout << endl;
    for (int& i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
