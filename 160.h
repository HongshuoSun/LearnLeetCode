
#ifndef LEETCODE_160_H
#define LEETCODE_160_H
#include "Common.h"
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aLength = 0;
        int bLength = 0;
        ListNode* tmp = headA;
        while(tmp!=nullptr){
            tmp = tmp->next;
            aLength++;
        }
        tmp = headB;
        while(tmp!=nullptr){
            tmp = tmp->next;
            bLength++;
        }
        while(aLength>bLength){
            aLength--;
            headA = headA->next;
        }
        while(bLength>aLength){
            bLength--;
            headB = headB->next;
        }
        while(headA!=headB&& headA!=nullptr && headB!=nullptr){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
#endif