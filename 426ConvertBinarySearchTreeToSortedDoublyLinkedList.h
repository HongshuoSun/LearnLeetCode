//
// Created by sun51 on 2019/5/24.
//

#ifndef LEETCODE_426CONVERTBINARYSEARCHTREETOSORTEDDOUBLYLINKEDLIST_H
#define LEETCODE_426CONVERTBINARYSEARCHTREETOSORTEDDOUBLYLINKEDLIST_H
#include "Common.h"
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        head = nullptr;
        Node* current = nullptr;
        stack<pair<Node*,int>> myStack;
        if(root!= nullptr){
            myStack.push(make_pair(root,0));
        }
        while(!myStack.empty()){
            auto top = myStack.top();
            if(top.first->left== nullptr || top.second>0){
                myStack.pop();
                if(top.first->right!= nullptr){
                    myStack.push(make_pair(top.first->right,0));
                }
                if(head== nullptr){ head = top.first; current = head;}

                current->right = top.first;
                top.first->left = current;
                current = current->right;
                current->right = head;
                head->left = current;
            }else{
                myStack.pop();
                myStack.push(make_pair(top.first,1));
                myStack.push(make_pair(top.first->left,0));
            }
        }
        return head;
    }
    Node* head;

};
#endif //LEETCODE_426CONVERTBINARYSEARCHTREETOSORTEDDOUBLYLINKEDLIST_H
