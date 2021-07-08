//
// Created by bugma on 7/6/2021.
//

#ifndef LEETCODE_148_H
#define LEETCODE_148_H
#include "Common.h"
class Solution {
private:
    ListNode* merge(ListNode* l1,ListNode *l2){
        ListNode* dummy = new ListNode(-1);
        dummy->next = nullptr;
        ListNode* cur = dummy;
        while(l1&&l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1=l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1){
            cur->next = l1;
        }
        if(l2){
            cur->next = l2;
        }
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next == nullptr){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast!=nullptr&& fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right = slow->next;
        slow->next = nullptr;
        ListNode* l1= sortList(head);
        ListNode* l2= sortList(right);
        return merge(l1,l2);
    }
};
#endif //LEETCODE_148_H
