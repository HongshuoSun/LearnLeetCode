//
// Created by bugma on 7/13/2021.
//

#ifndef LEETCODE_369_H
#define LEETCODE_369_H
#include "Common.h"
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> myStack;
        ListNode* node=head;
        while(node!= nullptr){
            myStack.push(node);
            node = node->next;
        }
        bool processed= false;
        int  num = 1;
        while(!myStack.empty() && num >0){
            ListNode* top = myStack.top();
            myStack.pop();
            num = (top->val+num);
            top->val = num %10;
            num = num/10;
        }
        if(num>0){
            ListNode* node = new ListNode(num);
            node->next = head;
            head = node;
        }
        return head;
    }
};
#endif //LEETCODE_369_H
