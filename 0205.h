//
// Created by bugma on 2022/1/25.
//

#ifndef LEETCODE_0205_H
#define LEETCODE_0205_H
#include "Common.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1,l2);
    }
    ListNode* add(ListNode* l1,ListNode* l2){
        static int jinwei = 0;
        ListNode * head = new ListNode(0);
        ListNode *p = head;
        while(l1!= nullptr || l2!= nullptr || jinwei>0){
            int num1 = l1!= nullptr?l1->val:0;
            int num2 = l2!= nullptr?l2->val:0;
            jinwei = num1+num2+jinwei;
            ListNode* cur = new ListNode(jinwei%10);
            jinwei/=10;
            p->next = cur;
            p = p->next;
            l1 = l1!= nullptr?l1->next: nullptr;
            l2 = l2!= nullptr?l2->next: nullptr;
        }
        if(head->next!= nullptr){
            return head->next;
        }else{
            return head;
        }
    }
};
#endif //LEETCODE_0205_H
