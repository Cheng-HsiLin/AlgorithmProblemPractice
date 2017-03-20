//
//  148_SortList.cpp
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

// // Mergesort Method (Unacceptable due to not constant space complexity)
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) { // time: O(nlogn); space: O(n) for the worst, O(logn) for average
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }
//         ListNode *slow = head, *fast = head;
//         while (fast->next != nullptr && fast->next->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         fast = slow->next;
//         slow->next = nullptr;
//         ListNode *l1 = sortList(head), *l2 = sortList(fast);
//         return merge(l1, l2);
//     }
// private:
//     ListNode* merge(ListNode* l1, ListNode* l2) {
//         ListNode* dummy = new ListNode(0);
//         ListNode* ptr = dummy;
//         while (l1 != nullptr && l2 != nullptr) {
//             if (l1->val < l2->val) {
//                 ptr->next = l1;
//                 l1 = l1->next;
//             } else {
//                 ptr->next = l2;
//                 l2 = l2->next;
//             }
//             ptr = ptr->next;
//         }
//         if (l1 != nullptr) {
//             ptr->next = l1;
//         }
//         if (l2 != nullptr) {
//             ptr->next = l2;
//         }
//         ListNode* newHead = dummy->next;
//         delete dummy;
//         return newHead;
//     }
// };

// Bottom-Up Mergesort Method
class Solution {
public:
    ListNode* sortList(ListNode* head) { // time: O(nlogn); space: O(1)
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // get the linked list's length
        ListNode* cur = head;
        int length = 0;
        while (cur != nullptr) {
            length++;
            cur = cur->next;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *left, *right, *tail;
        for (int step = 1; step < length; step <<= 1) {
            cur = dummy->next;
            tail = dummy;
            while (cur != nullptr) {
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
private:
    // Divide the linked list into two lists,
    // while the first list contains first n nodes
    // return the second list's head
    ListNode* split(ListNode* head, int n) {
        for (int i = 1; i < n && head != nullptr; i++) {
            head = head->next;
        }
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }
    
    // merge the two sorted linked list l1 and l2,
    // then append the merged sorted linked list to the node head
    // return the tail of the merged sorted linked list
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head) {
        ListNode* cur = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != nullptr) {
            cur->next = l1;
        }
        if (l2 != nullptr) {
            cur->next = l2;
        }
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        return cur;
    }
};

// Test
int main () {
    Solution solution;
    ListNode* head = new ListNode(3); // 3 -> 9 -> 2 -> 1
    head->next = new ListNode(9);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    ListNode* res = solution.sortList(head); // 1 -> 2 -> 3 -> 9
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
