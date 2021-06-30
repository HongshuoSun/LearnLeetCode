//
// Created by bugma on 6/29/2021.
//

#ifndef LEETCODE_23_H
#define LEETCODE_23_H
#include "Common.h"
template <typename T>
struct _less{
    bool operator()(const T& a ,const  T& b ){
        return a->val > b->val;
    }
};
class Solution {
    typedef typename std::vector<ListNode*>::iterator iterator;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listCount =lists.size();
        _less<ListNode*> op;
        priority_queue<ListNode*,std::vector<ListNode*>,_less<ListNode*>> myQueue(op);
        for(int i=0;i<listCount;i++){
            if(lists[i]!=nullptr){
                myQueue.push(lists[i]);
            }
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = nullptr;
        ListNode* last = dummy;
        while(!myQueue.empty()){
            auto cur = myQueue.top();
            myQueue.pop();
            last->next = cur;
            cur = cur->next;
            last = last->next;
            last->next = nullptr;
            if(cur!=nullptr){
                myQueue.push(cur);
            }
        }
        return dummy->next;
    }
};
#endif //LEETCODE_23_H
