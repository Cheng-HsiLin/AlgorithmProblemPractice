//
//  2AddTwoNumbers.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { // time: O(max(m, n)); space: (max(m, n))
        ListNode *head1 = l1, *head2 = l2; // pointers to the original input linked lists
        ListNode *dummy = new ListNode(-1); // dummy node for the result
        ListNode *p = dummy; // pointer to the dummy node
        int carry = 0, value = 0;
        
        while (head1 || head2) {
            value = carry + (head1 ? head1->val : 0) + (head2 ? head2->val : 0);
            carry = value / 10;
            value %= 10;
            p->next = new ListNode(value);
            p = p->next;
            if (head1) {
                head1 = head1->next;
            }
            if (head2) {
                head2 = head2->next;
            }
        }
        
        if (carry) {
            p->next = new ListNode(carry);
            p = p->next;
        }
        
        ListNode *res = dummy->next;
        delete dummy;
        
        return res;
    }
};

// Test
int main () {
    Solution solution;
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* res = solution.addTwoNumbers(l1, l2);
    ListNode* p = res;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}
