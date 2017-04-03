//
//  23_MergeKSortedLists.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/02/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) { // time: O(klogk * n); space: O(1), k: size of input
        if (lists.empty() == true) {
            return nullptr;
        }
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { // time: O(n), n: average length of lists
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* ptr = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if (l1 != nullptr) {
            ptr->next = l1;
        } else {
            ptr->next = l2;
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Test
int main () {
    Solution solution;
    ListNode* l1 = new ListNode(0);
    l1->next = new ListNode(2);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    ListNode* l3 = new ListNode(4);
    l3->next = new ListNode(6);
    ListNode* l4 = new ListNode(5);
    vector<ListNode*> lists({l1, l2, l3, l4});
    ListNode* res = solution.mergeKLists(lists);
    ListNode* p = res;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
