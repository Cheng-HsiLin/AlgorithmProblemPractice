//
//  242_ValidAnagram.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) { // time: O(n); space: O(1)
        int m = s.size(), n = t.size();
        if (m != n) {
            return false;
        }
        vector<int> record(26, 0); // follow up: record(128, 0)
        for (int i = 0; i < m; i++) {
            record[s[i] - 'a']++;
            record[t[i] - 'a']--;
        }
        for (int& t : record) {
            if (t != 0) {
                return false;
            }
        }
        return true;
    }
};

// Test
int main () {
    Solution solution;
    cout << (solution.isAnagram("anagram", "nagaram") ? "TRUE" : "FALSE") << endl;
    cout << (solution.isAnagram("rat", "car") ? "TRUE" : "FALSE") << endl;
    return 0;
}
