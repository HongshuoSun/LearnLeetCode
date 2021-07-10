#ifndef LEETCODE_147_H
#define LEETCODE_147_H
#include "Common.h"
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        while(head!=nullptr){
            ListNode* preNode = dummy;
            ListNode* cur = preNode->next;
            while(cur!=nullptr && cur->val< head->val){
                preNode = cur;
                cur = cur->next;
            }
            preNode->next = head;
            head = head->next;
            preNode->next->next = cur;
        }
        return dummy->next;
    }   
};
#endif