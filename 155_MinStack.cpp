//
//  155_MinStack.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/21/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        m_min = INT_MAX;
    }
    
    void push(int x) {
        if (x <= m_min) {
            m_stack.push(m_min);
            m_min = x;
        }
        m_stack.push(x);
    }
    
    void pop() {
        if (m_stack.top() == m_min) {
            m_stack.pop();
            m_min = m_stack.top();
            m_stack.pop();
        } else {
            m_stack.pop();
        }
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_min;
    }
private:
    stack<int> m_stack;
    int m_min;
};

// Test
int main () {
    MinStack minStack;
    minStack.push(3); // 3
    cout << minStack.getMin() << endl;
    minStack.push(2); // 3 2
    cout << minStack.top() << endl;
    minStack.pop(); // 3
    minStack.push(4); // 3 4
    cout << minStack.getMin() << endl;
    return 0;
}
