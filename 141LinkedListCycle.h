//
// Created by 孙宏硕 on 2019-05-10.
//

#ifndef LEETCODE_141LINKEDLISTCYCLE_H
#define LEETCODE_141LINKEDLISTCYCLE_H
#include "Common.h"
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto fast = head;
        auto low = head;
        while(fast!=NULL && low!=NULL&& low!=fast)
        {
            low = low->next;
            fast = fast->next;
            if(fast == NULL)
            {
                return false;
            }
            else
            {
                fast = fast->next;
            }
        }
        return fast!=nullptr;
    }
};
#endif //LEETCODE_141LINKEDLISTCYCLE_H
