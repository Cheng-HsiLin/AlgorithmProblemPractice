//
//  347_TopKFrequentElements.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/20/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// // Frequency-Based Array Method
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) { // time: O(n); space: O(n)
//         unordered_map<int, int> mp;
//         for (int num : nums) {
//             mp[num]++;
//         }
//         // the word frequency is at most nums.size()
//         vector<vector<int> > buckets(nums.size() + 1);
//         for (auto& p : mp) {
//             buckets[p.second].push_back(p.first);
//         }
//         vector<int> res;
//         for (int i = buckets.size() - 1; i >= 0 && res.size() < k; i--) {
//             for (int& num : buckets[i]) {
//                 res.push_back(num);
//                 if (res.size() == k) {
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };

// Max-Heap (Priority_queue) Based Method
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { // time: O(nlog(n-k)); space: O(n)
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int, int> > pq;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            // keep (size-k) smallest elements in the priority_queue
            // once the size bigger than size-k
            // pop the value which is the top k frequent element value
            if (pq.size() > mp.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1,1,1,2,2,3});
    vector<int> res = solution.topKFrequent(nums, 2);
    for (int& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
