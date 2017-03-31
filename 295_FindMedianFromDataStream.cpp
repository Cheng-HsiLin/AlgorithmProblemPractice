//
//  295_FindMedianFromDataStream.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/31/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Two Heaps Method
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) { // time: O(logn)
        if (maxHeap.empty() == true || maxHeap.top() > num) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        // Modulate the size of two heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() { // time: O(1)
        if (maxHeap.size() == minHeap.size()) {
            return maxHeap.empty() ? 0 : (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
};

// // Negation Method
// class MedianFinder {
// public:
//      /** initialize your data structure here. */
//      MedianFinder() {}

//      void addNum(int num) { // time: O(logn)
//          small.push(num);
//          large.push(-small.top());
//          small.pop();
//          if (small.size() < large.size()) {
//              small.push(-large.top());
//              large.pop();
//          }
//      }

//      double findMedian() { // time: O(1)
//          return small.size() > large.size() ? small.top() : (small.top() - large.top()) / 2.0;
//      }
// private:
//     priority_queue<int> small, large;
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

// Test
int main () {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << obj->findMedian() << endl; // 1.5
    obj->addNum(3);
    cout << obj->findMedian() << endl; // 2
    return 0;
}
