//
// Created by sun51 on 2019/5/24.
//

#ifndef LEETCODE_21MERGETWOSORTEDLISTS_H
#define LEETCODE_21MERGETWOSORTEDLISTS_H
#include "Common.h"
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1== nullptr || l2== nullptr){
            return l1!= nullptr?l1:l2;
        }
        ListNode* head = nullptr,*current = nullptr;
        l1->val<l2->val?(current = l1,l1 = l1->next):(current = l2,l2 = l2->next);
        head = current;
        current->next = nullptr;
        while(l1!= nullptr && l2!= nullptr){
            l1->val<l2->val?(current->next = l1,l1 = l1->next):(current->next = l2,l2 = l2->next);
            current = current->next;
        }
        current->next = nullptr;
        if(l1!= nullptr){
            current ->next = l1;
        }
        if(l2!= nullptr){
            current->next = l2;
        }
        return head;
    }
};
#endif //LEETCODE_21MERGETWOSORTEDLISTS_H
