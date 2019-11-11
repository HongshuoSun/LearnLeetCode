//
// Created by sun51 on 2019/11/11.
//

#ifndef LEETCODE_61_H
#define LEETCODE_61_H
#include "Common.h"
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0){
            return head;
        }
        int listLength = GetLength(head);
        if(listLength<1){
            return head;
        }
        k =listLength- ( k%listLength)-1;
        if(k<0){
            return head;
        }
        ListNode* current = head;
        int currentIndex = 0;
        while(currentIndex!=k){
            current = current->next;
            currentIndex++;
        }
        auto newHead = current->next;
        current->next = nullptr;
        return newHead;
    }
    inline int GetLength(ListNode* head){
        auto i = head;
        int ans = 0;
        while(i!= nullptr){
            ans++;
            if(i->next== nullptr){
                i->next = head;
                break;
            }
            i = i->next;
        }
        return ans;
    }
};
#endif //LEETCODE_61_H
