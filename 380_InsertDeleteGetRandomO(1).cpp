//
//  380_InsertDeleteGetRandomO(1).cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/28/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.count(val) != 0) {
            return false;
        }
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.count(val) == 0) {
            return false;
        }
        int last = nums.back();
        if (last != val) {
            mp[last] = mp[val];
            nums[mp[val]] = last;
        }
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> mp; // number -> index in vector
};

// Test
int main () {
    RandomizedSet obj;
    obj.insert(3);
    obj.insert(4);
    bool param_1 = obj.insert(2);
    bool param_2 = obj.remove(1);
    int param_3 = obj.getRandom();
    cout << (param_1 == true ? "True" : "False") << endl;
    cout << (param_2 == true ? "True" : "False") << endl;
    cout << param_3 << endl;
    return 0;
}
