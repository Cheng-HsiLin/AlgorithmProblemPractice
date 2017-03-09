//
//  141_LinkedListCycle.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/09/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
// Two Pointers Method
class Solution {
public:
    bool hasCycle(ListNode *head) { // time: (n); space: O(1)
        if (!head) {
            return false;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

// Test
int main () {
    Solution solution;
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    ListNode* circleBegin = head->next;
    head->next->next = new ListNode(2);
    head->next->next->next = circleBegin;
    if(solution.hasCycle(head)) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    return 0;
}
