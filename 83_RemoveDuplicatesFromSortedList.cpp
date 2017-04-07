//
//  83_RemoveDuplicatesFromSortedList.cpp
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
    ListNode* deleteDuplicates(ListNode* head) { // time: O(n); space: O(1)
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                ListNode* n = cur->next->next;
                delete cur->next;
                cur->next = n;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

// Test
int main () {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(3);
    ListNode* newHead = solution.deleteDuplicates(head);
    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead ->next;
    }
    cout << endl;
    return 0;
}
