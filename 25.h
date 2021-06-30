//
// Created by bugma on 2021/6/23.
//

#ifndef LEETCODE_25_H
#define LEETCODE_25_H
#include "Common.h"
class Solution {
public:
    std::pair<ListNode*,ListNode *> _reverse(ListNode* begin,ListNode* end){
        ListNode* current = begin;
        ListNode* head = current;
        ListNode* newEnd = begin;
        while(current!=end){
            ListNode* next = current->next;
            current->next = head;
            head = current;
            current = next;
        }
        return make_pair(head,newEnd);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy= new ListNode(0);
        dummy->next = head;
        ListNode* lastHeader = dummy;

        while(head!= nullptr){
            int i=0;
            ListNode* begin = head;
            for(i=0;i<k &&head!= nullptr;i++,head = head->next){
            }
            if(i<k){
                lastHeader->next =begin;
                break;
            }
            ListNode* end = head;
            std::pair<ListNode*,ListNode *> newNode = _reverse(begin,end);
            lastHeader->next = newNode.first;
            lastHeader = newNode.second;
            lastHeader->next = nullptr;
        }
        return dummy->next;
    }
};
#endif //LEETCODE_25_H
