//
//  142_LinkedListCycleII.cpp
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
    ListNode *detectCycle(ListNode *head) { // time: O(n); space: O(1)
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};

// Test
int main () {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode* p = head->next;
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = p;
    ListNode* entry = solution.detectCycle(head);
    cout << entry->val << endl;
    return 0;
}
