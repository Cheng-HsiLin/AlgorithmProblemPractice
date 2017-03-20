//
//  56_MergeIntervals.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/19/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) { // time: O(n*log(n)); space: O(n)
        vector<Interval> res;
        if (intervals.empty()) {
            return res;
        }
        auto comp = [](Interval a, Interval b) {
            return a.start < b.start;
        };
        // sort by the start position of each pair
        sort(intervals.begin(), intervals.end(), comp);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // overlapping, change the end of the latest element
            if (res.back().end >= intervals[i].start) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<Interval> merge(vector<Interval>& intervals) { // time: O(n*log(n)); space: O(n)
//         int n = intervals.size();
//         if (n <= 1) {
//             return intervals;
//         }
//         sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
//         vector<Interval> res;
//         int start = intervals[0].start, end = intervals[0].end;
//         for (Interval interval : intervals) {
//             if (interval.start <= end) {
//                 end = max(end, interval.end);
//             } else {
//                 res.push_back(Interval(start, end));
//                 start = interval.start;
//                 end = interval.end;
//             }
//         }
//         res.push_back(Interval(start, end));
//         return res;
//     }
// };

// Test
int main () {
    Solution solution;
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));
    vector<Interval> res = solution.merge(intervals);
    for (auto& i : res) {
        cout << "[" << i.start << "," << i.end << "] ";
    }
    cout << endl;
    return 0;
}
