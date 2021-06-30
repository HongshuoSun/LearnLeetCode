//
// Created by bugma on 2021/6/23.
//

#ifndef LEETCODE_24_H
#define LEETCODE_24_H
#include "Common.h"
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return _swap(head);
    }
    ListNode* _swap(ListNode* node){
        if(!node || !node->next){
            return node;
        }
        ListNode* current = node;
        ListNode* next = node->next;
        current->next = next->next;
        next->next = current;
        current->next = _swap(current->next);
        return next;
    }
};
#endif //LEETCODE_24_H
