//
// Created by bugma on 7/12/2021.
//

#ifndef LEETCODE_707_H
#define LEETCODE_707_H
//#include "Common.h"
class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
public:
    ListNode* dummy;
    MyLinkedList() {
        dummy = new ListNode(-1);
    }
    ~MyLinkedList(){
        ListNode* cur = dummy->next;
        while(cur!= nullptr){
            ListNode* tmp = cur->next;
            delete(cur);
            cur = tmp;
        }
        delete(dummy);
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int idx=0;
        ListNode* node = dummy->next;
        while(node!= nullptr && idx<index){
            node = node->next;
            idx++;
        }
        return node!=nullptr?node->val:-1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = dummy->next;
        dummy->next = node;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* pre = dummy;
        while(pre->next!= nullptr){
            pre = pre->next;
        }
        ListNode* node = new ListNode(val);
        node->next = nullptr;
        pre->next = node;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int idx=0;
        ListNode* pre = dummy;
        while(pre!= nullptr && idx<index){
            pre = pre->next;
            idx++;
        }
        if(idx==index){
            ListNode* node = new ListNode(val);
            node->next = pre->next;
            pre->next = node;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int idx=0;
        ListNode* pre = dummy;
        while(pre->next!= nullptr && idx<index){
            pre = pre->next;
            idx++;
        }
        if(pre->next!= nullptr && idx == index){
            pre->next = pre->next->next;
        }
    }
};

#endif //LEETCODE_707_H
