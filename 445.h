//
// Created by bugma on 7/6/2021.
//

#ifndef LEETCODE_445_H
#define LEETCODE_445_H
#include "Common.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while(l1!=nullptr&& l1->val==0){
            l1=l1->next;
        }
        while(l2!=nullptr&& l2->val==0){
            l2=l2->next;
        }
        return _add(l1,l2);
    }
    ListNode* _add(ListNode* l1,ListNode* l2){
        std::stack<int> s1;
        std::stack<int> s2;
        while(l1!=nullptr){
            s1.push(l1->val);
            l1= l1->next;
        }
        while(l2!=nullptr){
            s2.push(l2->val);
            l2= l2->next;
        }
        int num = 0;
        ListNode* ansNode = new ListNode(0);
        while(!s1.empty() &&!s2.empty()){
            num += s1.top()+s2.top();
            s1.pop();
            s2.pop();
            int curNum = num%10;
            ListNode* curNode = new ListNode(curNum);
            curNode->next = ansNode->next;
            ansNode->next = curNode;
            num = num/10;
        }
        while(!s1.empty()){
            num += s1.top();
            s1.pop();
            int curNum = num%10;
            ListNode* curNode = new ListNode(curNum);
            curNode->next = ansNode->next;
            ansNode->next = curNode;
            num = num/10;
        }
        while(!s2.empty()){
            num += s2.top();
            s2.pop();
            int curNum = num%10;
            ListNode* curNode = new ListNode(curNum);
            curNode->next = ansNode->next;
            ansNode->next = curNode;
            num = num/10;
        }
        while(num>0){
            int curNum = num%10;
            ListNode* curNode = new ListNode(curNum);
            curNode->next = ansNode->next;
            ansNode->next = curNode;
            num = num/10;
        }
        if(ansNode->next==nullptr){
            return ansNode;
        }
        else{
            return ansNode->next;
        }
    }
};
#endif //LEETCODE_445_H
