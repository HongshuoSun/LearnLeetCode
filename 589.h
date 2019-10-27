//
// Created by sun51 on 2019/10/27.
//

#ifndef LEETCODE_589_H
#define LEETCODE_589_H
#include "Common.h"
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> myStack;
        vector<int> ans;
        if(root!= nullptr){
            myStack.push(root);
        }
        while(!myStack.empty()){
            auto current = myStack.top();
            myStack.pop();
            ans.push_back(current->val);
            for(auto it = current->children.rbegin();it!=current->children.rend();it++){
                if(*it!= nullptr){
                    myStack.push(*it);
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_589_H
