//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_142_H
#define LEETCODE_142_H
#include "Common.h"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* intersection = GetIntersection(head);
        if(intersection == nullptr){
            return nullptr;
        }
        ListNode* begin = head;
        while(begin!=intersection){
            begin = begin->next;
            intersection = intersection->next;
        }
        return begin;
    }
    ListNode *GetIntersection(ListNode *head){
        ListNode* fast = head;
        ListNode* low = head;
        while(fast!= nullptr && fast->next != nullptr){
            fast = fast->next->next;
            low = low->next;
            if(fast==low){
                return low;
            }
        }
        return nullptr;
    }
};
#endif //LEETCODE_142_H
