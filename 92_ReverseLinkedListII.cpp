//
//  92_ReverseLinkedListII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/10/17.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) { // time: O(length of list); space: O(1)
        if (head == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        pre->next = head;
        for (int i = 1; i < m; i++) {
            pre = pre->next;
        }
        ListNode* p = pre->next;
        ListNode* nex = p->next;
        for (int i = m; i < n; i++) {
            p->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = p->next;
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
    head->next->next->next->next = new ListNode(5);
    ListNode* res = solution.reverseBetween(head, 2, 4);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
