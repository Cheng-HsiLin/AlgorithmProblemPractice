//
//  134_GasStation.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/13/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { // time: O(n); space: O(1)
        int start = 0, tank = 0, total = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            total += tank;
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        if (total < 0) { // Invalid Input
            return -1;
        } else {
            return start;
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<int> gas({1,2,3,4,5,6,7});
    vector<int> cost({1,3,3,3,2,5,4});
    cout << solution.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
