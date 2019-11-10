//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_141_H
#define LEETCODE_141_H
#include "Common.h"
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* low = head;
        while(fast!= nullptr && low!=nullptr){
            fast = fast->next;
            if(fast ==low){
                return true;
            }
            if(fast== nullptr){
                break;
            }
            fast = fast->next;
            low = low->next;
            if(fast ==low){
                return true;
            }
        }
        return false;
    }
};
#endif //LEETCODE_141_H
