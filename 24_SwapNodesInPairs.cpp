//
//  24_SwapNodesInPairs.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/03/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) { // time: O(n); space: O(1)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *p = dummy;
        while (p != nullptr && p->next != nullptr && p->next->next != nullptr) {
            ListNode *n = p->next, *nn = p->next->next;
            p->next = nn;
            n->next = nn->next;
            nn->next = n;
            p = p->next->next;
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Test
int main () {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    ListNode* res = solution.swapPairs(head);
    ListNode* ptr = res;
    while (ptr != nullptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
    return 0;
}
