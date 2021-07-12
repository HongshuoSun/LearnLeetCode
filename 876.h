//
// Created by bugma on 7/12/2021.
//

#ifndef LEETCODE_876_H
#define LEETCODE_876_H
#include "Common.h"
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast= dummy;
        ListNode* slow = dummy;
        while(fast->next!= nullptr && fast->next->next!= nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow!= nullptr && slow->next!= nullptr){
            slow = slow->next;
        }
        return slow;
    }
};
#endif //LEETCODE_876_H
