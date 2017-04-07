//
//  86_PartitionList.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/07/17.
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
    ListNode* partition(ListNode* head, int x) { // time: O(n); space: O(1)
        if (head == nullptr) {
            return head;
        }
        ListNode *dummy1 = new ListNode(INT_MIN), *dummy2 = new ListNode(INT_MIN);
        ListNode *cur = head, *p1 = dummy1, *p2 = dummy2;
        while (cur != nullptr) {
            if (cur->val < x) {
                p1->next = cur;
                p1 = p1->next;
            } else {
                p2->next = cur;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        p1->next = dummy2->next;
        p2->next = nullptr;
        ListNode *newHead = dummy1->next;
        delete dummy1, dummy2;
        return newHead;
    }
};

// Test
int main () {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    ListNode* newHead = solution.partition(head, 3);
    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead ->next;
    }
    cout << endl;
    return 0;
}
