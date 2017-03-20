//
//  49_GroupAnagrams.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/20/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { // time: O(n), space: O(n)
        vector<vector<string> > res;
        if (strs.empty() == true) {
            return res;
        }
        unordered_map<string, vector<string> > mp;
        for (string ss : strs) {
            string str = strSort(ss);
            mp[str].push_back(ss);
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<string> anagram(it->second.begin(), it->second.end());
            res.push_back(anagram);
        }
        return res;
    }
private:
    string strSort(string& s) { // O(n); STL sort(): O(nlogn)
        vector<int> count(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }
        int pos = 0;
        string res(n, 'a');
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < count[j]; k++) {
                res[pos++] += j;
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<string> str({"eat", "tea", "tan", "ate", "nat", "bat"});
    vector<vector<string> > res = solution.groupAnagrams(str);
    for (auto& v : res) {
        for (string& s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
