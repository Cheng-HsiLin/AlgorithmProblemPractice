//
//  237_DeleteNodeInALinkedList.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/11/17.
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
    void deleteNode(ListNode* node) { // time: O(1); space: O(1)
        ListNode* next = node->next;
        *node = *next;
        delete next;
    }
};

// class Solution {
// public:
//     void deleteNode(ListNode* node) { // time: O(1); space: O(1)
//         ListNode* next = node->next;
//         node->val = next->val;
//         node->next = next->next;
//         delete next;
//     }
// };
