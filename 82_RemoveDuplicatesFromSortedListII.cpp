//
//  82_RemoveDuplicatesFromSortedListII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/29/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// // Iterative Method
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) { // time: O(n); space: O(1)
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }
//         ListNode *dummy = new ListNode(head->val - 1), *pre = dummy, *cur = head;
//         dummy->next = head;
//         while (cur != nullptr) {
//             if (cur->next != nullptr && cur->val == cur->next->val) {
//                 int curVal = cur->val;
//                 while (cur != nullptr && cur->val == curVal) {
//                     ListNode *toBeDeleted = cur;
//                     cur = cur->next;
//                     delete toBeDeleted;
//                 }
//                 pre->next = cur;
//             } else {
//                 pre = cur;
//                 cur = cur->next;
//             }
//         }
//         ListNode* newHead = dummy->next;
//         delete dummy;
//         return newHead;
//     }
// };

// Recursive Method
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) { // time: O(n); space: O(n)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int curVal = head->val;
        ListNode* p = head->next;
        if (p->val != curVal) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            delete head;
            while (p != nullptr && p->val == curVal) {
                ListNode* toBeDeleted = p;
                p = p->next;
                delete toBeDeleted;
            }
        }
        return deleteDuplicates(p);
    }
};

// Test
int main () {
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    ListNode* res = solution.deleteDuplicates(head);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
