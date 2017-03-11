//
//  206_ReverseLinkedList.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// // Iterative Method With Dummy Node
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) { // time: O(n); space: O(1)
//         // Validtate Input
//         if (!head) {
//             return head;
//         }
//         ListNode* dummy = new ListNode(-1);
//         dummy->next = head;
//         ListNode *pre = dummy, *cur = head, *n;
//         while (cur->next) {
//             n = cur->next;
//             cur->next = n->next;
//             n->next = pre->next;
//             pre->next = n;
//         }
//         ListNode* new_head = dummy->next;
//         delete dummy;
//         return new_head;
//     }
// };

// Iterative Method Without Dummy Node
class Solution {
public:
    ListNode* reverseList(ListNode* head) { // time: O(n); space: O(1)
        if (!head) {
            return head;
        }
        ListNode *pre = nullptr, *cur = head, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

// // Recursive Method
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) { // time: O(n); space: O(n)
//         if (!head || !head->next) {
//             return head;
//         }
//         ListNode* new_head = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return new_head;
//     }
// };

// Test
int main () {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    ListNode* res = solution.reverseList(head);
    ListNode* ptr = res;
    while (ptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
    return 0;
}
