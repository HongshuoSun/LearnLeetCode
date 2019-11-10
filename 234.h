//
// Created by sun51 on 2019/11/10.
//

#ifndef LEETCODE_234_H
#define LEETCODE_234_H
#include "Common.h"
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow =head;
        ListNode* fast = head;
        if(slow== nullptr||slow->next== nullptr){
            return true;
        }
        while(fast!= nullptr&& fast->next!= nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast!= nullptr){
            auto tmp = slow->next;
            slow->next = nullptr;
            slow = tmp;
        }
        ListNode *secondHead = slow;
        ListNode *secondCurrent = secondHead->next;
        secondHead->next = nullptr;
        while(secondCurrent!= nullptr){
            auto next = secondCurrent->next;
            secondCurrent->next = secondHead;
            secondHead = secondCurrent;
            secondCurrent = next;
        }
        bool  isPalindrome = true;
        while(secondHead!= nullptr){
            if(head->val != secondHead->val){
                isPalindrome =false;
                break;
            }
            secondHead = secondHead->next;
            head = head->next;
        }
        return isPalindrome;
    }
};
#endif //LEETCODE_234_H
