//
//  109_ConvertSortedListToBinarySearchTree.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/11/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) { // time: O(nlogn); space: O(logn)
        if (head == nullptr) {
            return nullptr;
        }
        return build(head, nullptr);
    }
private:
    TreeNode* build(ListNode* start, ListNode* end) {
        if (start == end) {
            return nullptr;
        }
        ListNode* slow = start;
        ListNode* fast = start;
        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = build(start, slow);
        node->right = build(slow->next, end);
        return node;
    }
};

// Test
int main () {
    Solution solution;
    ListNode* head = new ListNode(5);
    head->next = new ListNode(10);
    head->next->next = new ListNode(15);
    head->next->next->next = new ListNode(20);
    head->next->next->next->next = new ListNode(25);
    head->next->next->next->next->next = new ListNode(30);
    head->next->next->next->next->next->next = new ListNode(35);
    TreeNode* res = solution.sortedListToBST(head);
    queue<TreeNode*> q;
    q.push(res);
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            TreeNode* cur = q.front();
            q.pop();
            cout << cur->val << " ";
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        cout << endl;
    }
    return 0;
}
