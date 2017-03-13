//
//  160_IntersectionOfTwoLinkedLists.cpp
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

// Two Pointers Method
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { // time: O(n); space: O(1)
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode *p1 = headA, *p2 = headB;
        while (p1 && p2 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2) {
                return p1;
            }
            if (!p1) {
                p1 = headB;
            }
            if (!p2) {
                p2 = headA;
            }
        }
        return p1;
    }
};

// Test
int main () {
    Solution solution;
    ListNode *headA = new ListNode(2);
    headA->next = new ListNode(4);
    headA->next->next = new ListNode(6);
    headA->next->next->next = new ListNode(8);
    headA->next->next->next->next = new ListNode(10);
    ListNode *headB = new ListNode(3);
    headB->next = new ListNode(4);
    headB->next->next = new ListNode(5);
    headB->next->next->next = headA->next->next;
    ListNode* res = solution.getIntersectionNode(headA, headB);
    cout << res->val << endl;
    return 0;
}
