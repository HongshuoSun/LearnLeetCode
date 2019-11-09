//
// Created by sun51 on 2019/11/9.
//

#ifndef LEETCODE_86_H
#define LEETCODE_86_H
#include "Common.h"
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = nullptr;
        ListNode* greaterHead = nullptr;
        ListNode* lessCurrent = nullptr;
        ListNode* greaterCurrent = nullptr;
        ListNode* current = head;
        while(current!= nullptr){
            auto tmp = current->next;
            current->next = nullptr;
            if(current->val<x){
                if(lessHead== nullptr){
                    lessHead = current;
                    lessCurrent = lessHead;
                }else{
                    lessCurrent->next = current;
                    lessCurrent=lessCurrent->next;
                }
            }else{
                if(greaterHead== nullptr){
                    greaterHead = current;
                    greaterCurrent = greaterHead;
                }else{
                    greaterCurrent->next = current;
                    greaterCurrent=greaterCurrent->next;
                }
            }
            current = tmp;
        }
        ListNode* ans = lessHead;
        if(ans!= nullptr){
            lessCurrent->next = greaterHead;
        }else{
            ans = greaterHead;
        }
        return ans;
    }
};
#endif //LEETCODE_86_H
