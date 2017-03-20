//
//  19_RemoveNthNodeFromEndOfList.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/20/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Two Pointers
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { // time: O(n); space: O(1)
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy, *slow = dummy;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Test
int main () {
    Solution solution;
    ListNode* head = new ListNode(3); // 3 -> 9 -> 2 -> 1
    head->next = new ListNode(9);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    ListNode* res = solution.removeNthFromEnd(head, 2);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
