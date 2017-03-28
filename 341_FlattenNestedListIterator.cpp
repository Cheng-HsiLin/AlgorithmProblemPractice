//
//  341_FlattenNestedListIterator.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/28/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        int val = st.top().getInteger();
        st.pop();
        return val;
    }
    
    bool hasNext() {
        while (st.empty() == false) {
            NestedInteger cur = st.top();
            if (cur.isInteger() == true) {
                return true;
            }
            st.pop();
            for (int i = cur.getList().size() - 1; i >= 0; i--) {
                st.push((cur.getList())[i]);
            }
        }
        return false;
    }
private:
    stack<NestedInteger> st;
};
