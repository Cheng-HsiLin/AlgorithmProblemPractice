//
//  21_MergeTwoSortedLists.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/12/17.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { // time: O(n); space: O(1)
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* ptr = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if (l1) {
            ptr->next = l1;
        } else {
            ptr->next = l2;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

// Test
int main () {
    Solution solution;
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(3);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(6);
    l2->next = new ListNode(5);
    l2->next->next = new ListNode(9);
    ListNode* head = solution.mergeTwoLists(l1, l2);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
