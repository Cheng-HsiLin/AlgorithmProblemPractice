//
//  328_OddEvenLinkedList.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/11/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) { // time: O(n); space: O(1)
        if (head) {
            ListNode *p1 = head, *p2 = head->next, *evenHead = p2;
            while (p1->next && p2->next) {
                p1->next = p1->next->next;
                p2->next = p2->next->next;
                p1 = p1->next;
                p2 = p2->next;
            }
            p1->next = evenHead;
        }
        return head;
    }
};

// Test
int main () {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* res = solution.oddEvenList(head);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
