//
// Created by sun51 on 2019/11/9.
//

#ifndef LEETCODE_382_H
#define LEETCODE_382_H
#include "Common.h"
class Solution {
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    ListNode* head;
    int getRandom() {
        ListNode* ans = head;
        ListNode* currentNode = ans->next;
        int count = 2;
        while(currentNode!=nullptr){
            int randInt = std::rand()%count;
            if(randInt==0){
                ans = currentNode;
            }
            count++;
            currentNode = currentNode->next;
        }
        return ans->val;
    }
};
#endif //LEETCODE_382_H
